//
// Created by Chiniaev on 10.05.2022.
//

#ifndef MY_PROJECT_COORDINATES_HPP
#define MY_PROJECT_COORDINATES_HPP

struct CartesianCoordinates {
    double x_ = 0.;     // X-axis coordinate [km]
    double y_ = 0.;     // Y-axis coordinate [km]
    double z_ = 0.;     // Z-axis coordinate [km]
    double vx_ = 0.;    // X-axis velocity component [km/s]
    double vy_ = 0.;    // Y-axis velocity component [km/s]
    double vz_ = 0.;    // Z-axis velocity component [km/s]
};

struct KeplerianCoordenates {
    double a_ = 0.;     // Semi-major axis [km]
    double e_ = 0.;     // Eccentricity [1]
    double i_ = 0.;     // Inclination [rad]
    double w_ = 0.;     // Argument of periapsis [rad]
    double n_ = 0.;     // Longitude of ascending node [rad]
    double v_ = 0.;     // True anomaly [rad]
};

#endif //MY_PROJECT_COORDINATES_HPP
