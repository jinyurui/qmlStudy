#include "registry.h"

namespace reg_helper
{
/**
 * @brief Generates a key from a type
 */
template <typename T>
std::type_index mapKey()
{
    return std::type_index(typeid(T));
}

/**
 * @brief States if an instance is null
 */
template <typename T, template <class> class RefType>
bool isNull(RefType<T> value)
{
    return (nullptr == value);
}
/**
 * @brief Stattes if a weak pointer now refers to a null pointer (or about to be null)
 */
template <typename T>
bool isNull(std::weak_ptr<T> value)
{
    return value.expired();
}

/**
 * @brief Generic static cast
 */
template <typename T, template <class> class RefType>
RefType<T> static_cast_to(RefType<void> value)
{
    return std::static_pointer_cast<T>(value);
}

/**
 * @brief Static cast for a weak pointer
 */
template <typename T>
std::weak_ptr<T> static_cast_to(std::weak_ptr<void> value)
{
    return std::static_pointer_cast<T>(value.lock());
}
}  // namespace reg_helper

template <template <class> class RefType>
template <typename T>
RefType<T> Registry<RefType>::getInstance() const
{
    std::lock_guard<std::mutex> lock(m_instancesMutex);
    try
    {
        return reg_helper::static_cast_to<T>(m_instances.at(reg_helper::mapKey<T>()));
    }
    catch (std::out_of_range)
    {
        return RefType<T>();
    }
}

template <template <class> class RefType>
template <typename T>
bool Registry<RefType>::registerInstance(RefType<T> instance)
{
    if (reg_helper::isNull(instance))
    {
        return false;
    }

    std::lock_guard<std::mutex> lock(m_instancesMutex);
    const auto                  ret = m_instances.insert(std::make_pair(reg_helper::mapKey<T>(), instance));
    return ret.second;
}

template <template <class> class RefType>
template <typename T>
bool Registry<RefType>::replaceInstance(RefType<T> instance)
{
    if (reg_helper::isNull(instance))
    {
        return false;
    }
    std::lock_guard<std::mutex> lock(m_instancesMutex);
    auto                        it = m_instances.find(reg_helper::mapKey<T>());
    if (it == std::end(m_instances))
    {
        return false;
    }
    it->second = instance;
    return true;
}

template <template <class> class RefType>
template <typename T>
bool Registry<RefType>::removeInstance()
{
    std::lock_guard<std::mutex> lock(m_instancesMutex);
    auto                        it = m_instances.find(reg_helper::mapKey<T>());
    if (it == std::end(m_instances))
    {
        return false;
    }

    m_instances.erase(it);
    return true;
}

template <template <class> class RefType>
void Registry<RefType>::removeAll()
{
    std::lock_guard<std::mutex> lock(m_instancesMutex);
    m_instances.clear();
}
