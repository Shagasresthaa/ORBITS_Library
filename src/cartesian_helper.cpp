#include <stdexcept>
#include "cartesian_helper.hpp"

namespace orbits {

    // Compute the magnitude of 3D vector
    double magnitude(const std::array<double, 3>& vec) {
        return std::sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
    }

     // Compute the angular momentum vector
    std::array<double, 3> angular_momentum(const std::array<double, 3>& position, const std::array<double, 3>& velocity) {
        return {
            position[1] * velocity[2] - position[2] * velocity[1],
            position[2] * velocity[0] - position[0] * velocity[2],
            position[0] * velocity[1] - position[1] * velocity[0]
        };
    }

    // Compute the dot product of two 3D vectors
    double dot_product(const std::array<double, 3>& v1, const std::array<double, 3>& v2) {
        return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    }

    // Compute the relative angle between two vectors
    double relative_angle(const std::array<double, 3>& v1, const std::array<double, 3>& v2) {
        double dot = dot_product(v1, v2);
        double mag1 = magnitude(v1);
        double mag2 = magnitude(v2);

        if (mag1 == 0.0 || mag2 == 0.0) {
            throw std::runtime_error("Cannot calculate relative angle with zero-magnitude vectors.");
        }

        double cos_theta = dot / (mag1 * mag2);

        // Clamp cos_theta to [-1, 1] to avoid domain errors in acos due to floating-point imprecision
        cos_theta = std::max(-1.0, std::min(1.0, cos_theta));

        return std::acos(cos_theta);  // Returns angle in radians
    }

}
