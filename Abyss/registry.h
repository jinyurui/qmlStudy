#ifndef REGISTRY_H
#define REGISTRY_H

#include <mutex>
#include <memory>
#include <map>
#include <typeindex>

/**
 * @class Registry
 * @brief Generic references registry
 */
template <template <class> class RefType>
class Registry
{
public:
    /**
     * @brief Gets an existing instance
     *        Returns nullptr the desired instance is not found
     *
     * @return RefType<T>
     */
    template <typename T>
    RefType<T> getInstance() const;

    /**
     * @brief Registers an instance
     *        Returns false if the provided instance was not registered or if a nullptr provided
     *
     * @param instance - The registered instance
     * @return bool
     */
    template <typename T>
    bool registerInstance(RefType<T> instance);

    /**
     * @brief Replaces an existing instance
     *        Returns false if the provided instance Type was not already registered or if a nullptr provided
     *
     * @param instance - The replacement instance
     * @return bool
     */
    template <typename T>
    bool replaceInstance(RefType<T> instance);

    /**
     * @brief Removes an instance of a given type T
     *        Returns false if the instance type was not registered
     *
     * @return bool
     */
    template <typename T>
    bool removeInstance();

    /**
     * @brief Remove all registered instances
     */
    void removeAll();

private:
    using Container = std::map<std::type_index, RefType<void>>;

    mutable std::mutex m_instancesMutex;
    /**
     * @brief Registered instances container
     */
    Container m_instances;
};

#include "registry.tpp"

#endif  // REGISTRY_H
