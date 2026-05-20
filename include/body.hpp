#ifndef BODY_HPP
#define BODY_HPP

#include "cartesian_helper.hpp"
#include "orbital_parameters.hpp"
#include <string>

namespace orbits {

    class Body {
    public:
        Body(const std::string& name, double mu, double radius);
        Body(const std::string& name, double mu, double radius, const Pos3D& state);

        const std::string& name() const;
        double mu() const;
        double radius() const;
        const Pos3D& state() const;
        void set_state(const Pos3D& state);

        // Orbital parameters of this body relative to a central body with the given mu
        OrbitalParameters orbital_parameters(double central_mu) const;

        // Sphere of influence radius: a * (mu / central_mu)^(2/5)
        double sphere_of_influence(double central_mu, double semi_major_axis) const;

    private:
        std::string _name;
        double _mu;
        double _radius;
        Pos3D _state;
    };

}

#endif
