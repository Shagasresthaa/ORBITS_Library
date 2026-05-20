# ORBITS Library

**Orbital Research and Body Interaction Toolkit for Simulations** — a C++17 library for estimating orbital parameters and simulating basic orbital mechanics.

> Work in progress.

## Units

All quantities use metric units throughout:

| Quantity | Unit |
|---|---|
| Position | km |
| Velocity | km/s |
| Angle | radians |
| Gravitational parameter `mu` | km³/s² |

## Build

```bash
mkdir -p build && cd build && cmake .. && make
./main    # manual test driver, run from inside build/
```

Requires CMake ≥ 3.10 and a C++17-capable compiler.

## Modules

### `cartesian_helper`
Low-level 3D vector math. All functions operate on `std::array<double, 3>`.

| Symbol | Description |
|---|---|
| `Pos3D` | Struct holding a position vector and velocity vector |
| `magnitude(v)` | Euclidean norm |
| `dot_product(v1, v2)` | Scalar dot product |
| `angular_momentum(r, v)` | Cross product r × v |
| `relative_angle(v1, v2)` | Angle between two vectors (radians), clamped for floating-point safety |

### `orbital_parameters`
`OrbitalParameters` — constructed from position, velocity, and `mu` of the central body.

| Method | Description |
|---|---|
| `semi_major_axis()` | Vis-viva equation: `1 / (2/r − v²/mu)` |
| `eccentricity()` | Magnitude of the eccentricity vector |
| `inclination()` | Angle between angular momentum vector and z-axis (reference normal) |

### `body`
`Body` — represents a celestial body (planet, moon, satellite, etc.).

**Construction:**
```cpp
// Central body (state defaults to origin)
orbits::Body earth("Earth", 398600.4418, 6371.0);

// Orbiting body with known state
orbits::Body moon("Moon", 4902.8, 1737.4,
    orbits::Pos3D({384400.0, 0.0, 0.0}, {0.0, 1.022, 0.0}));
```

| Method | Description |
|---|---|
| `name()` | Body name string |
| `mu()` | Gravitational parameter GM (km³/s²) |
| `radius()` | Mean body radius (km) |
| `state()` | Current `Pos3D` (position + velocity) |
| `set_state(pos3d)` | Update position/velocity |
| `orbital_parameters(central_mu)` | Returns `OrbitalParameters` for this body's current state |
| `sphere_of_influence(central_mu, sma)` | SOI radius: `a × (mu/central_mu)^(2/5)` (km) |

## Example

```cpp
#include "body.hpp"

orbits::Body earth("Earth", 398600.4418, 6371.0);
orbits::Body sat("SAT-1", 0.0, 0.5,
    orbits::Pos3D({7000.0, 0.0, 0.0}, {0.0, 7.5, 0.0}));

auto orb = sat.orbital_parameters(earth.mu());
std::cout << orb.semi_major_axis() << " km\n";   // semi-major axis
std::cout << orb.eccentricity()    << "\n";       // eccentricity
std::cout << orb.inclination()     << " rad\n";   // inclination
```

## Namespace

Everything lives in the `orbits` namespace.

## License

See [LICENSE](LICENSE).
