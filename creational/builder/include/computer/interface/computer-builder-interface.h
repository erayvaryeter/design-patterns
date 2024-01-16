#pragma once

#include <iostream>
#include <string>
#include <memory>

namespace builder {

class Computer;

enum class ComputerRam {
    GB_4 = 0,
    GB_8 = 1,
    GB_16 = 2,
    GB_32 = 3,
    GB_64 = 4,
    GB_128 = 5,
    GB_256 = 6
};

enum class GraphicsCard {
    AMD = 0,
    INTEL = 1,
    NVIDIA = 2
};

enum class OperatingSystem {
    FREEDOS = 0,
    LINUX = 1,
    MAC = 2,
    WINDOWS = 3
};

class ComputerBuilder {
public:
    virtual void buildRAM() = 0;
    virtual void buildGraphicsCard() = 0;
    virtual void buildOperatingSystem() = 0;
    virtual std::shared_ptr<Computer> getResult() = 0;
};

}