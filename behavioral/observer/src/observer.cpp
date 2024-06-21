#include "observer/observer.h"

void Subject::attach(Observer* observer)
{
	m_observers.push_back(observer);
}

void Subject::detach(Observer* observer)
{
    auto it = std::find(m_observers.begin(), m_observers.end(), observer);
    if (it != m_observers.end()) {
        m_observers.erase(it);
    }
}

void Subject::notify(int reason, void* userData)
{
    for (auto& observer : m_observers) {
        observer->update(reason, userData);
    }
}