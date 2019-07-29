#ifndef VARFUN_H
#define VARFUN_H

/**
 * @class Callback is a generic callback wrapper
 * It captures member function pointers and allows using operator() for calling the member function with arguments
 * @brief
 * @tparam T
 * @tparam Args
 */
template <typename T, typename... Args>
class Callback
{
public:
    typedef void (T::*F)(Args...);

    Callback(T& t, F f)
        : m_t(&t)
        , m_f(f)
    {
    }

    template <typename... Args_>
    void operator()(Args_... args)
    {
        (m_t->*m_f)(args...);
    }

private:
    T* m_t;
    F  m_f;
};

template <typename T, typename... Args>
Callback<T, Args...> make_callback(T& t, void (T::*f)(Args...))
{
    return Callback<T, Args...>(t, f);
}
#endif // VARFUN_H
