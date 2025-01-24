#ifndef CARTESIAN_HELPER_HPP
#define CARTESIAN_HELPER_HPP

#include <array>
#include <cmath>

/*
 * Uses metric units only
 */

namespace orbits{
	
	struct Pos3D{

		// {x, y, z} Position Coordinates in km
		std::array<double, 3> position;

		// {Vx, Vy, Vz} Velocity Vector Components in km/sec
		std::array<double, 3> velocity;

		Pos3D() : position{0.0, 0.0, 0.0}, velocity{0.0, 0.0, 0.0} {}
        Pos3D(const std::array<double, 3>& pos, const std::array<double, 3>& vel) : position(pos), velocity(vel) {}
    };

    // Function to compute the magnitude of 3D vector
    double magnitude(const std::array<double, 3>& vec);

	// Compute the angular momentum vector (cross product of r and v)
    std::array<double, 3> angular_momentum(const std::array<double, 3>& position, const std::array<double, 3>& velocity);

    // Compute the dot product of two 3D vectors
    double dot_product(const std::array<double, 3>& v1, const std::array<double, 3>& v2);

	// Compute the relative angle between two 3D vectors
	double relative_angle(const std::array<double, 3>& v1, const std::array<double, 3>& v2);

}

#endif

