#include "cartesian_helper.hpp"

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

    return 0;
}

