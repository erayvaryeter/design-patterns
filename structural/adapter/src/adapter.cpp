#include "adapter/adapter.h"

double CelsiusWeatherProvider::GetTemperatureCelsius()
{
	return 25.0;
}

double CelsiusToFahrenheitAdapter::GetTemperatureFahrenheit()
{
	double celsius = m_celsiusProvider->GetTemperatureCelsius();
	return (celsius * 9 / 5) + 32;
}