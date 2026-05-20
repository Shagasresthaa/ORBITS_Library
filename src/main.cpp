#include "cartesian_helper.hpp"
#include "orbital_parameters.hpp"
#include "body.hpp"

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

    // --- Test 4: Body ---
    // Earth as a central body, Moon as an orbiting body
    double mu_moon = 4902.8;       // km³/s²
    double radius_moon = 1737.4;   // km
    double mu_sun = 1.327124e11;   // km³/s²

    orbits::Body earth("Earth", mu_earth, 6371.0);
    orbits::Body moon("Moon", mu_moon, radius_moon,
        orbits::Pos3D({384400.0, 0.0, 0.0}, {0.0, 1.022, 0.0}));

    std::cout << "Body name: " << moon.name() << "\n";
    std::cout << "Body mu: " << moon.mu() << " km^3/s^2\n";
    std::cout << "Body radius: " << moon.radius() << " km\n";

    orbits::OrbitalParameters moon_orbit = moon.orbital_parameters(earth.mu());
    std::cout << "Moon semi-major axis: " << moon_orbit.semi_major_axis() << " km\n";
    std::cout << "Moon eccentricity: " << moon_orbit.eccentricity() << "\n";
    std::cout << "Moon inclination: " << moon_orbit.inclination() << " radians\n";

    double moon_sma = moon_orbit.semi_major_axis();
    double soi = moon.sphere_of_influence(earth.mu(), moon_sma);
    std::cout << "Moon sphere of influence: " << soi << " km\n";

    return 0;
}

