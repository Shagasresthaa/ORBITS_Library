#include "orbital_parameters.hpp"
#include <cmath>

namespace orbits {

    // Initialize orbital parameters with position, velocity, and gravitational parameter
    OrbitalParameters::OrbitalParameters(const std::array<double, 3>& position, const std::array<double, 3>& velocity, double mu)
        : r(position), v(velocity), mu(mu) {}

    // Compute the semi-major axis using vis-viva equation
    double OrbitalParameters::semi_major_axis() const {
        double r_mag = magnitude(r);
        double v_mag = magnitude(v);
        return 1.0 / ((2.0 / r_mag) - ((v_mag * v_mag) / mu));
    }

    // Compute the orbital eccentricity using the eccentricity vector formula
    double OrbitalParameters::eccentricity() const {
        std::array<double, 3> h = angular_momentum(r, v);
        double h_mag = magnitude(h);
        double r_mag = magnitude(r);
        double v_mag = magnitude(v);
        
        // Compute eccentricity vector
        std::array<double, 3> e_vector = {
            ((v_mag * v_mag - mu / r_mag) * r[0] - (dot_product(r, v) * v[0])) / mu,
            ((v_mag * v_mag - mu / r_mag) * r[1] - (dot_product(r, v) * v[1])) / mu,
            ((v_mag * v_mag - mu / r_mag) * r[2] - (dot_product(r, v) * v[2])) / mu
        };

        return magnitude(e_vector);
    }

    // Compute orbital inclination as the angle between angular momentum and reference normal (z-axis)
    double OrbitalParameters::inclination() const {
        std::array<double, 3> h = angular_momentum(r, v);
        std::array<double, 3> k = {0.0, 0.0, 1.0};  // Reference normal
        return relative_angle(h, k);
    }

}
