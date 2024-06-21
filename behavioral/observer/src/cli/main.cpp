#include <observer/observer.h>

enum NotificationIDs : int {
	eNewTemperature = 0,
	eNewHumidity = 1,
	eNewPressure = 2
};

class WeatherStation : public Subject {
public:
	void setTemperature(float temperature)
	{
		m_temperature = temperature;
		notify(eNewTemperature, &m_temperature);
	}

	void setHumidity(float humidity)
	{
		m_humidity = humidity;
		notify(eNewHumidity, &m_humidity);
	}

	void setPressure(float pressure)
	{
		m_pressure = pressure;
		notify(eNewPressure, &m_pressure);
	}

private:
	float m_temperature = 0.0f;
	float m_humidity = 0.0f;
	float m_pressure = 0.0f;
};

class WeatherDisplay : public Observer {
public:
	WeatherDisplay(const std::string displayName) : m_displayName(displayName) {}

	void update(int reason, void* userData) override
	{
		switch (reason) {
		case eNewTemperature:
		{
			float* temperature = static_cast<float*>(userData);
			std::cout << "Name: " << m_displayName << " - Temperature: " << *temperature << std::endl;
			break;
		}
		case eNewHumidity:
		{
			float* humidity = static_cast<float*>(userData);
			std::cout << "Name: " << m_displayName << " - Humidity: " << *humidity << std::endl;
			break;
		}
		case eNewPressure:
		{
			float* pressure = static_cast<float*>(userData);
			std::cout << "Name: " << m_displayName << " - Pressure: " << *pressure << std::endl;
			break;
		}
		default: break;
		}
	}

private:
	std::string m_displayName;
};

int main()
{
	WeatherStation station;
	WeatherDisplay display1("Display1");
	WeatherDisplay display2("Display2");
	WeatherDisplay display3("Display3");

	station.attach(&display1);
	station.attach(&display2);
	station.attach(&display3);

	station.setHumidity(100.0f);
	station.setPressure(50.0f);
	station.setTemperature(25.0f);

	station.detach(&display1);
	station.detach(&display2);
	station.detach(&display3);

	station.setHumidity(200.0f);
	station.setPressure(100.0f);
	station.setTemperature(50.0f);

	return 0;
}