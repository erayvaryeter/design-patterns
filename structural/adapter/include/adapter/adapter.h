#pragma once

#include <iostream>
#include <memory>

class CelsiusWeatherProvider {
public:
    double GetTemperatureCelsius();
};

class FahrenheitWeatherProvider {
public:
    virtual double GetTemperatureFahrenheit() = 0;
};

class CelsiusToFahrenheitAdapter : public FahrenheitWeatherProvider {
public:
    CelsiusToFahrenheitAdapter(CelsiusWeatherProvider* provider) : m_celsiusProvider(provider) {}
    double GetTemperatureFahrenheit() override;

private:
    CelsiusWeatherProvider* m_celsiusProvider;
};