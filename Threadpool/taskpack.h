#ifndef TASKPACK_H
#define TASKPACK_H

#include <memory>
#include <future>
#include <type_traits>

// primary template
template <class T>
class PackagedTask;

/**
 * @brief This is a replacemnt of std::packaged_task until
 * @param R - return type
 * @param Args - arguments of the call
 */
template <typename R, typename... Args>
class PackagedTask<R(Args...)>
{
private:
    /**
     * @brief type erasure concept
     */
    struct Concept
    {
        virtual ~Concept() = default;
        /**
         * @brief invokes the stored callable
         * @param args - variadic args to pass
         */
        virtual void invoke(Args&&... args) = 0;
        /**
         * @brief gets the underlying promise
         * @return
         */
        virtual std::promise<R>& getPromise() = 0;
    };

    /**
     * @brief Model implements the Concept
     */
    template <typename F>
    struct Model : Concept
    {
        /**
         * @brief ctor pf the Model
         * @param f - callable to store internally
         */
        Model(const F& f)
            : m_f(f)
        {
        }

        /**
         * @brief ctor pf the Model
         * @param f - callable to store internally
         */
        Model(F&& f)
            : m_f(std::move(f))
        {
        }

        // implementation of Concept
        void invoke(Args&&... args) override
        {
            try
            {
                invoke(std::is_same<R, void>{}, std::forward<Args>(args)...);
            }
            // catch any exception user thrown at the function call site
            // and store it for rethrowing when future.get() is called
            catch (...)
            {
                m_promise.set_exception(std::current_exception());
            }
        }

        /**
         * @brief overload for R != void
         */
        void invoke(std::false_type, Args&&... args)
        {
            auto result = m_f(std::forward<Args>(args)...);
            m_promise.set_value(result);
        }

        /**
         * @brief overload for R = void
         */
        void invoke(std::true_type, Args&&... args)
        {
            m_f(std::forward<Args>(args)...);
            m_promise.set_value();
        }

        std::promise<R>& getPromise() override
        {
            return m_promise;
        }

        F               m_f;
        std::promise<R> m_promise;
    };

    std::unique_ptr<Concept> m_concept;

public:
    /**
     * @brief Constructs from a deduced constant functor
     * @param f - functor to store
     */
    template <typename F>
    PackagedTask(const F& f)
        : m_concept(new Model<typename std::decay<F>::type>(f))
    {
    }

    /**
     * @brief Constructs from a functor with perfect forwarding
     * @param f - callable to store
     */
    template <typename F>
    PackagedTask(F&& f)
        : m_concept(new Model<typename std::decay<F>::type>(std::forward<F>(f)))
    {
    }

    /**
     * @brief return the associated future that will have it's shared state set when calling operator()(Args... args)
     * @return
     */
    std::future<R> getFuture()
    {
        return m_concept->getPromise().get_future();
    }

    /**
     * @brief invokes the stored callable and set shared state
     * @param args - args for callable
     */
    void operator()(Args... args)
    {
        m_concept->invoke(std::forward<Args>(args)...);
    }
};

#endif  // PACKAGED_TASK_H
