#include "cartesian_helper.hpp"

#include <iostream>

int main() {
    // Define a test position and respective velocity vectors in 3D space
    orbits::Pos3D state({1.0, 2.0, 2.0}, {0.0, 0.0, 0.0});

    // Calculate and print the magnitude of the position
    double distance = orbits::magnitude(state.position);
    std::cout << "Distance from origin: " << distance << " km" << std::endl;

    return 0;
}

