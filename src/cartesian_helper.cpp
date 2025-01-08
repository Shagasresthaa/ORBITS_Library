#include "cartesian_helper.hpp"

namespace orbits {

    // Compute the magnitude of 3D vector
    double magnitude(const std::array<double, 3>& vec) {
        return std::sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
    }

}

