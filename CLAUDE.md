# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

ORBITS Library (Orbital Research and Body Interaction Toolkit for Simulations) is a C++17 library for estimating orbital parameters and simulating basic orbital mechanics. All units are metric: positions in **km**, velocities in **km/s**, angles in **radians**, gravitational parameter `mu` in **km³/s²**.

## Build

```bash
mkdir -p build && cd build && cmake .. && make
./main          # run from inside build/
```

No test framework yet — `src/main.cpp` serves as a manual test driver with inline assertions printed to stdout.

## Architecture

Everything lives in the `orbits` namespace. There are two active modules:

**`cartesian_helper`** (`include/cartesian_helper.hpp`, `src/cartesian_helper.cpp`)  
Low-level vector math: `magnitude`, `dot_product`, `angular_momentum` (cross product of r×v), `relative_angle` (returns acos of normalized dot product, clamped for floating-point safety). Also defines `Pos3D` — a struct holding a 3D position and velocity as `std::array<double, 3>`.

**`orbital_parameters`** (`include/orbital_parameters.hpp`, `src/orbital_parameters.cpp`)  
`OrbitalParameters` class: constructed from position, velocity, and `mu` (GM of central body). Computes:
- `semi_major_axis()` — vis-viva equation
- `eccentricity()` — eccentricity vector magnitude
- `inclination()` — angle between angular momentum vector and z-axis (reference normal)

**`body`** (`include/body.hpp`, `src/body.cpp`)  
`Body` class: represents a celestial body. Constructed with a name, `mu` (km³/s²), radius (km), and an optional `Pos3D` state. Provides:
- `orbital_parameters(central_mu)` — constructs and returns an `OrbitalParameters` for the body's current state
- `sphere_of_influence(central_mu, semi_major_axis)` — SOI radius via `a × (mu/central_mu)^(2/5)`
- `set_state(pos3d)` — update position/velocity as a simulation advances
- Getters: `name()`, `mu()`, `radius()`, `state()`

`OrbitalParameters` delegates all vector math to the free functions in `cartesian_helper`, which it includes directly.

`Body::orbital_parameters()` delegates to `OrbitalParameters`, keeping the dependency chain: `body` → `orbital_parameters` → `cartesian_helper`.
