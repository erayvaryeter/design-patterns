#include <computer/computer.h>
#include <vector>

int main() {
    // assembler
    builder::ComputerAssembler assembler;
    // builders
    builder::ModelA_ComputerBuilder modelABuilder;
    builder::ModelB_ComputerBuilder modelBBuilder;
    builder::ModelC_ComputerBuilder modelCBuilder;
    builder::ModelD_ComputerBuilder modelDBuilder;
    // specify which model computers will be created and store in a vector
    std::vector<std::shared_ptr<builder::Computer>> computers;
    // append to the vector
    auto computerModelA = assembler.AssembleComputer(modelABuilder);
    computers.push_back(computerModelA);
    auto computerModelB = assembler.AssembleComputer(modelBBuilder);
    computers.push_back(computerModelB);
    auto computerModelC = assembler.AssembleComputer(modelCBuilder);
    computers.push_back(computerModelC);
    auto computerModelD = assembler.AssembleComputer(modelDBuilder);
    computers.push_back(computerModelD);
    // print all computer features
    for (auto& computer : computers)
        computer->PrintComputerFeatures();
	return 0;
}