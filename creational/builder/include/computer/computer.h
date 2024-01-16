#pragma once

#include "interface/computer-builder-interface.h"

namespace builder {

// Product Class
class Computer {
public:
	Computer(const std::string& name);
	void SetComputerRam(ComputerRam ram);
	void SetGraphicsCard(GraphicsCard graphicsCard);
	void SetOperatingSystem(OperatingSystem os);
	void PrintComputerFeatures();

private:
	ComputerRam m_ram;
	GraphicsCard m_graphicsCard;
	OperatingSystem m_operatingSystem;
	std::string m_name;
};

class ModelA_ComputerBuilder : public ComputerBuilder {
public:
	ModelA_ComputerBuilder();
	void buildRAM() override;
	void buildGraphicsCard() override;
	void buildOperatingSystem() override;
	std::shared_ptr<Computer> getResult() override;
private:
	std::shared_ptr<Computer> m_computer;
};

class ModelB_ComputerBuilder : public ComputerBuilder {
public:
	ModelB_ComputerBuilder();
	void buildRAM() override;
	void buildGraphicsCard() override;
	void buildOperatingSystem() override;
	std::shared_ptr<Computer> getResult() override;
private:
	std::shared_ptr<Computer> m_computer;
};

class ModelC_ComputerBuilder : public ComputerBuilder {
public:
	ModelC_ComputerBuilder();
	void buildRAM() override;
	void buildGraphicsCard() override;
	void buildOperatingSystem() override;
	std::shared_ptr<Computer> getResult() override;
private:
	std::shared_ptr<Computer> m_computer;
};

class ModelD_ComputerBuilder : public ComputerBuilder {
public:
	ModelD_ComputerBuilder();
	void buildRAM() override;
	void buildGraphicsCard() override;
	void buildOperatingSystem() override;
	std::shared_ptr<Computer> getResult() override;
private:
	std::shared_ptr<Computer> m_computer;
};

// Director
class ComputerAssembler {
public:
	std::shared_ptr<Computer> AssembleComputer(ComputerBuilder& builder) {
		builder.buildRAM();
		builder.buildGraphicsCard();
		builder.buildOperatingSystem();
		return builder.getResult();
	}
};

}