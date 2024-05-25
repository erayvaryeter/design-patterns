#pragma once

#include <iostream>
#include <vector>
#include <memory>

class Connection {
public:
	void SetConnectionID(int ID) { std::cout << "Setting connection ID to " << ID << std::endl;  m_connectionID = ID; }
	void Connect() { std::cout << "Connection established, ID: " << m_connectionID << std::endl;  }

private:
	int m_connectionID;
};

template<typename T>
class ObjectPool {
public:
	ObjectPool(int size);
	~ObjectPool();

	std::shared_ptr<T> AcquireObject();
	void ReleaseObject(std::shared_ptr<T> object);

private:
	int m_poolSize;
	std::vector<std::shared_ptr<T>> m_pool;
};