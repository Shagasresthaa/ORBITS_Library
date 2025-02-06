#include "cartesian_helper.hpp"
#include "orbital_parameters.hpp"

#include <iostream>

int main() {
    // --- Test 1: Magnitude ---
    std::array<double, 3> vector = {3.0, 4.0, 0.0};  // A simple 3-4-5 triangle vector
    double mag = orbits::magnitude(vector);
    std::cout << "Magnitude Test: Expected 5.0, Got " << mag << "\n";

    // --- Test 2: Dot Product ---
    std::array<double, 3> v1 = {1.0, 2.0, 3.0};
    std::array<double, 3> v2 = {4.0, 5.0, 6.0};
    double dot = orbits::dot_product(v1, v2);
    std::cout << "Dot Product Test: Expected 32.0, Got " << dot << "\n";

    // Calculate angle between v1 and v2 (in radians)
    double angle_radians = orbits::relative_angle(v1, v2);
    std::cout << "Relative Angle Test (Radians): " << angle_radians << "\n";

    // --- Test 3: Cross Product (Angular Momentum) ---
    std::array<double, 3> position = {1.0, 0.0, 0.0};
    std::array<double, 3> velocity = {0.0, 1.0, 0.0};
    std::array<double, 3> angular_momentum = orbits::angular_momentum(position, velocity);

    std::cout << "Cross Product Test (Angular Momentum): Expected {0.0, 0.0, 1.0}, Got {"
              << angular_momentum[0] << ", "
              << angular_momentum[1] << ", "
              << angular_momentum[2] << "}\n";

    /*
    * Orbital Parameter tests
    */
    // Define position (r) and velocity (v) vectors in km and km/s
    std::array<double, 3> pos1 = {7000.0, 0.0, 0.0};  // Example: 7000 km from Earth's center
    std::array<double, 3> vel1 = {0.0, 7.5, 0.0};     // Example: 7.5 km/s in y direction

    // Standard gravitational parameter for Earth (mu = GM, in km^3/s^2)
    double mu_earth = 398600.4418;

    // Initialize orbital parameters
    orbits::OrbitalParameters orbit(pos1, vel1, mu_earth);

    // Compute and print semi-major axis
    double a = orbit.semi_major_axis();
    std::cout << "Semi-Major Axis: " << a << " km\n";

    // Compute and print eccentricity
    double e = orbit.eccentricity();
    std::cout << "Eccentricity: " << e << "\n";

    // Compute and print inclination
    double i = orbit.inclination();
    std::cout << "Inclination: " << i << " radians\n";

    return 0;
}

