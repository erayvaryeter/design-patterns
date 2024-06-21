#pragma once

#include <iostream>
#include <vector>

class Observer {
public:
	virtual void update(int reason, void* userData = nullptr) = 0;
};

class Subject {
public:
	void attach(Observer* observer);
	void detach(Observer* observer);
	void notify(int reason, void* userData = nullptr);

private:
	std::vector<Observer*> m_observers;
};