#include "object-pool/object-pool.h"

template<typename T>
ObjectPool<T>::ObjectPool(int size) :
	m_poolSize(size)
{
	for (int i = 0; i < m_poolSize; ++i) {
		auto object = std::make_shared<T>();
		m_pool.push_back(object);
	}
}

template<typename T>
ObjectPool<T>::~ObjectPool()
{
	for (auto& obj : m_pool) {
		obj.reset();
	}
}

template<typename T>
std::shared_ptr<T> ObjectPool<T>::AcquireObject()
{
	if (m_pool.empty()) {
		std::cout << "Pool is empty, can not acquire object" << std::endl;
		return nullptr;
	}

	auto object = m_pool.back();
	m_pool.pop_back();
	return object;
}

template<typename T>
void ObjectPool<T>::ReleaseObject(std::shared_ptr<T> object)
{
	if (object == nullptr) {
		std::cout << "Given object is null" << std::endl;
	}
	else if (m_pool.size() < m_poolSize) {
		m_pool.push_back(object);
		std::cout << "Object release back to pool" << std::endl;
	}
	else {
		std::cout << "Object pool is full, cannot release object" << std::endl;
	}
}

template class ObjectPool<Connection>;