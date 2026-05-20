#include "body.hpp"
#include <cmath>

namespace orbits {

    Body::Body(const std::string& name, double mu, double radius)
        : _name(name), _mu(mu), _radius(radius), _state() {}

    Body::Body(const std::string& name, double mu, double radius, const Pos3D& state)
        : _name(name), _mu(mu), _radius(radius), _state(state) {}

    const std::string& Body::name() const { return _name; }
    double Body::mu() const { return _mu; }
    double Body::radius() const { return _radius; }
    const Pos3D& Body::state() const { return _state; }

    void Body::set_state(const Pos3D& state) { _state = state; }

    OrbitalParameters Body::orbital_parameters(double central_mu) const {
        return OrbitalParameters(_state.position, _state.velocity, central_mu);
    }

    // r_SOI = a * (mu / central_mu)^(2/5)
    double Body::sphere_of_influence(double central_mu, double semi_major_axis) const {
        return semi_major_axis * std::pow(_mu / central_mu, 2.0 / 5.0);
    }

}
