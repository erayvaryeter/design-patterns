#include <adapter/adapter.h>
#include <vector>

int main()
{
	CelsiusWeatherProvider celsiusProvider;
	CelsiusToFahrenheitAdapter adapter(&celsiusProvider);

	std::cout << "Temperature in celcius: " << celsiusProvider.GetTemperatureCelsius() << std::endl;
	std::cout << "Temperature in fahrenheit: " << adapter.GetTemperatureFahrenheit() << std::endl;

	return 0;
}