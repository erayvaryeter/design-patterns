#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Threat {
public:
	Threat(uint16_t threatID, float azimuth, float elevation)
		: m_threatID(threatID),
		m_azimuth(azimuth),
		m_elevation(elevation)
	{
		// std::cout << "Threat Constructor" << std::endl;
	}
		
	virtual ~Threat() {
		// std::cout << "Threat Destructor" << std::endl;
	}

	virtual void PrintBasicThreatInfo() {
		std::cout << "Threat ID: " << m_threatID << std::endl;
		std::cout << "Azimuth: " << m_azimuth << std::endl;
		std::cout << "Elevation: " << m_elevation << std::endl;
	}

	virtual void PrintDetailedThreatInfo() = 0;

private:
	uint16_t m_threatID;
	float m_azimuth;
	float m_elevation;
};

class MissileThreat : public Threat {
public:
	MissileThreat(double speed, double velocity, uint16_t threatID, float azimuth, float elevation) : 
		m_speed(speed),
		m_velocity(velocity),
		Threat(threatID, azimuth, elevation)
	{
		// std::cout << "Missile Threat Constructor" << std::endl;
	}

	~MissileThreat()
	{
		// std::cout << "Missile Threat Destructor" << std::endl;
	}

	void PrintDetailedThreatInfo() override {
		std::cout << "Missile Threat Speed: " << m_speed << std::endl;
		std::cout << "Missile Threat Velocity: " << m_velocity << std::endl;
	}

private:
	double m_speed;
	double m_velocity;
};

class RadarThreat : public Threat {
public:
	RadarThreat(double frequency, double signalStrength, uint16_t threatID, float azimuth, float elevation) :
		m_frequency(frequency),
		m_signalStrength(signalStrength),
		Threat(threatID, azimuth, elevation)
	{
		// std::cout << "Radar Threat Constructor" << std::endl;
	}

	~RadarThreat()
	{
		// std::cout << "Radar Threat Destructor" << std::endl;
	}

	void PrintDetailedThreatInfo() override {
		std::cout << "Radar Threat Frequency: " << m_frequency << std::endl;
		std::cout << "Radar Threat Signal Strength: " << m_signalStrength << std::endl;
	}

private:
	double m_frequency;
	double m_signalStrength;
};

class Logger {
public:
	static Logger& GetInstance() {
		static Logger instance;
		return instance;
	}

	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
	
	Logger& operator<<(Threat& threat) {
		m_mutex.lock();
		threat.PrintBasicThreatInfo();
		threat.PrintDetailedThreatInfo();
		m_mutex.unlock();
		return *this;
	}

private:
	Logger() = default;
	~Logger() = default;

	std::mutex m_mutex;
};

std::vector<Threat*> SimulateMissileThreats(int numberOfThreats) {
	std::vector<Threat*> threats;
	for (int i = 0; i < numberOfThreats; ++i) {
		Threat* threat = new MissileThreat(i * 1, i * 2, i, i * 3, i * 4);
		threats.push_back(threat);
	}
	return threats;
}

std::vector<Threat*> SimulateRadarThreats(int numberOfThreats) {
	std::vector<Threat*> threats;
	for (int i = 0; i < numberOfThreats; ++i) {
		Threat* threat = new RadarThreat(i * 1, i * 2, i, i * 3, i * 4);
		threats.push_back(threat);
	}
	return threats;
}

void PrintAndDeleteThreats(std::vector<Threat*> threats) {
	for (auto th : threats) {
		Logger::GetInstance() << *th;
		delete th;
	}
}

int main() {
	auto threats1 = SimulateMissileThreats(50);
	auto threats2 = SimulateRadarThreats(75);
	auto threats3 = SimulateMissileThreats(100);
	auto threats4 = SimulateRadarThreats(25);
	auto threats5 = SimulateMissileThreats(50);
	auto threats6 = SimulateRadarThreats(75);
	auto threats7 = SimulateMissileThreats(100);
	auto threats8 = SimulateRadarThreats(25);

	std::thread t1(PrintAndDeleteThreats, threats1);
	std::thread t2(PrintAndDeleteThreats, threats2);
	std::thread t3(PrintAndDeleteThreats, threats3);
	std::thread t4(PrintAndDeleteThreats, threats4);
	std::thread t5(PrintAndDeleteThreats, threats5);
	std::thread t6(PrintAndDeleteThreats, threats6);
	std::thread t7(PrintAndDeleteThreats, threats7);
	std::thread t8(PrintAndDeleteThreats, threats8);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();

	return 0;
}

