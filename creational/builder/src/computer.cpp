#include "computer/computer.h"

namespace builder {

Computer::Computer(const std::string& name) : m_name(name) {}
void Computer::SetComputerRam(ComputerRam ram) { m_ram = ram; }
void Computer::SetGraphicsCard(GraphicsCard graphicsCard) { m_graphicsCard = graphicsCard; }
void  Computer::SetOperatingSystem(OperatingSystem os) { m_operatingSystem = os; }

void
Computer::PrintComputerFeatures() {
	std::cout << "----- " << m_name << " COMPUTER FEATURES -----" << std::endl;
	
	std::cout << "RAM: ";
	if (m_ram == ComputerRam::GB_4)
		std::cout << "4 GB" << std::endl;
	else if (m_ram == ComputerRam::GB_8)
		std::cout << "8 GB" << std::endl;
	else if (m_ram == ComputerRam::GB_16)
		std::cout << "16 GB" << std::endl;
	else if (m_ram == ComputerRam::GB_32)
		std::cout << "32 GB" << std::endl;
	else if (m_ram == ComputerRam::GB_64)
		std::cout << "64 GB" << std::endl;
	else if (m_ram == ComputerRam::GB_128)
		std::cout << "128 GB" << std::endl;
	else if (m_ram == ComputerRam::GB_256)
		std::cout << "256 GB" << std::endl;

	std::cout << "Graphics Card: ";
	if (m_graphicsCard == GraphicsCard::AMD)
		std::cout << "AMD" << std::endl;
	else if (m_graphicsCard == GraphicsCard::INTEL)
		std::cout << "INTEL" << std::endl;
	else if (m_graphicsCard == GraphicsCard::NVIDIA)
		std::cout << "NVIDIA" << std::endl;

	std::cout << "Operating System: ";
	if (m_operatingSystem == OperatingSystem::FREEDOS)
		std::cout << "FREEDOS" << std::endl;
	else if (m_operatingSystem == OperatingSystem::LINUX)
		std::cout << "LINUX" << std::endl;
	else if (m_operatingSystem == OperatingSystem::MAC)
		std::cout << "MAC" << std::endl;
	else if (m_operatingSystem == OperatingSystem::WINDOWS)
		std::cout << "WINDOWS" << std::endl;

	std::cout << "-------------------------------------------" << std::endl;
}

ModelA_ComputerBuilder::ModelA_ComputerBuilder() { m_computer = std::make_shared<Computer>("MODEL A"); }
void ModelA_ComputerBuilder::buildRAM() { m_computer->SetComputerRam(ComputerRam::GB_16); }
void ModelA_ComputerBuilder::buildGraphicsCard() { m_computer->SetGraphicsCard(GraphicsCard::INTEL); }
void ModelA_ComputerBuilder::buildOperatingSystem() { m_computer->SetOperatingSystem(OperatingSystem::LINUX); }
std::shared_ptr<Computer> ModelA_ComputerBuilder::getResult() { return m_computer; }

ModelB_ComputerBuilder::ModelB_ComputerBuilder() { m_computer = std::make_shared<Computer>("MODEL B"); }
void ModelB_ComputerBuilder::buildRAM() { m_computer->SetComputerRam(ComputerRam::GB_128); }
void ModelB_ComputerBuilder::buildGraphicsCard() { m_computer->SetGraphicsCard(GraphicsCard::AMD); }
void ModelB_ComputerBuilder::buildOperatingSystem() { m_computer->SetOperatingSystem(OperatingSystem::WINDOWS); }
std::shared_ptr<Computer> ModelB_ComputerBuilder::getResult() { return m_computer; }

ModelC_ComputerBuilder::ModelC_ComputerBuilder() { m_computer = std::make_shared<Computer>("MODEL C"); }
void ModelC_ComputerBuilder::buildRAM() { m_computer->SetComputerRam(ComputerRam::GB_32); }
void ModelC_ComputerBuilder::buildGraphicsCard() { m_computer->SetGraphicsCard(GraphicsCard::NVIDIA); }
void ModelC_ComputerBuilder::buildOperatingSystem() { m_computer->SetOperatingSystem(OperatingSystem::FREEDOS); }
std::shared_ptr<Computer> ModelC_ComputerBuilder::getResult() { return m_computer; }

ModelD_ComputerBuilder::ModelD_ComputerBuilder() { m_computer = std::make_shared<Computer>("MODEL D"); }
void ModelD_ComputerBuilder::buildRAM() { m_computer->SetComputerRam(ComputerRam::GB_64); }
void ModelD_ComputerBuilder::buildGraphicsCard() { m_computer->SetGraphicsCard(GraphicsCard::AMD); }
void ModelD_ComputerBuilder::buildOperatingSystem() { m_computer->SetOperatingSystem(OperatingSystem::MAC); }
std::shared_ptr<Computer> ModelD_ComputerBuilder::getResult() { return m_computer; }

}