#ifndef ORBITAL_PARAMETERS_HPP
#define ORBITAL_PARAMETERS_HPP

#include "cartesian_helper.hpp"
#include <array>

namespace orbits {

    class OrbitalParameters {
    public:
        OrbitalParameters(const std::array<double, 3>& position, const std::array<double, 3>& velocity, double mu);
        
        double semi_major_axis() const;
        double eccentricity() const;
        double inclination() const;

    private:
        std::array<double, 3> r;  // Position vector
        std::array<double, 3> v;  // Velocity vector
        double mu;                // Gravitational parameter (GM of the central body)
    };

}

#endif
