#include <computer/computer.h>
#include <vector>

struct GeographicalCoordinates {
    int16_t latitudeDegree = 0;
    int8_t latitudeMinute = 0;
    int8_t latitudeSecond = 0;
    int16_t longitudeDegree = 0;
    int8_t longitudeMinute = 0;
    int8_t longitudeSecond = 0;
    bool latitudeValid = false;
    bool longitudeValid = false;
};

bool isPointInsideSpace(const GeographicalCoordinates& point, const std::vector<GeographicalCoordinates>& coordinates) {
    // Define the reference point
    double refLatDeg = point.latitudeDegree;
    double refLatMin = point.latitudeMinute / 60.0;
    double refLatSec = point.latitudeSecond / 3600.0;
    double refLonDeg = point.longitudeDegree;
    double refLonMin = point.longitudeMinute / 60.0;
    double refLonSec = point.longitudeSecond / 3600.0;

    // Iterate through the coordinates
    int numCoords = coordinates.size();
    int intersections = 0;

    for (int i = 0; i < numCoords; ++i) {
        // Define the current coordinate
        const GeographicalCoordinates& coord = coordinates[i];
        double latDeg = coord.latitudeDegree;
        double latMin = coord.latitudeMinute / 60.0;
        double latSec = coord.latitudeSecond / 3600.0;
        double lonDeg = coord.longitudeDegree;
        double lonMin = coord.longitudeMinute / 60.0;
        double lonSec = coord.longitudeSecond / 3600.0;

        // Check if the latitude and longitude are valid
        if (!coord.latitudeValid || !coord.longitudeValid) {
            continue; // Skip invalid coordinates
        }

        // Check if the point's latitude is within the latitude range of the current coordinate
        if ((latDeg + latMin + latSec <= refLatDeg + refLatMin + refLatSec && latDeg + latMin + latSec >= refLatDeg - refLatMin - refLatSec) ||
            (latDeg - latMin - latSec <= refLatDeg + refLatMin + refLatSec && latDeg - latMin - latSec >= refLatDeg - refLatMin - refLatSec)) 
        {
            // Check if the point's longitude is to the left of the current coordinate
            if (lonDeg + lonMin + lonSec < refLonDeg + refLonMin + refLonSec) 
            {
                ++intersections;
            }
        }
    }

    // If the number of intersections is odd, the point is inside the space
    return (intersections % 2 == 1);
}

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