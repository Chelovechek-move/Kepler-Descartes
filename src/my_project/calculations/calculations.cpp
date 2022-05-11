//
// Created by vladimir on 11.05.22.
//

#include "my_project/calculations/calculations.hpp"

KeplerianCoordenates Cartesian_to_Keplerian(const CartesianCoordinates& coord) {
    KeplerianCoordenates new_coord;
    Vector3 r = {coord.x_, coord.y_, coord.z_};
    Vector3 v = {coord.vx_, coord.vy_, coord.vz_};
    const double m = 398600.4415;

    Vector3 h = r.VectorMultiplyBy(v);
    Vector3 e = v.VectorMultiplyBy(h) / m - r / r.GetNorm();
    Vector3 unit_vector = {0., 0., 1.};
    Vector3 n = unit_vector.VectorMultiplyBy(h);

    if (r.ScalarMultiplyBy(v) >= 0) {
        new_coord.v_ = acos(e.ScalarMultiplyBy(r) / (e.GetNorm() * r.GetNorm()));
    } else {
        new_coord.v_ = 2 * M_PI - acos(e.ScalarMultiplyBy(r) / (e.GetNorm() * r.GetNorm()));
    }
    new_coord.i_ = acos(h.GetV3() / h.GetNorm());
    new_coord.e_ = e.GetNorm();

    if (n.GetV2() >= 0) {
        new_coord.n_ = acos(n.GetV1() / n.GetNorm());
    } else {
        new_coord.n_ = 2 * M_PI - acos(n.GetV1() / n.GetNorm());
    }

    if (e.GetV3() >= 0) {
        new_coord.w_ = acos(n.ScalarMultiplyBy(e) / (n.GetNorm() * e.GetNorm()));
    } else {
        new_coord.w_ = 2 * M_PI - acos(n.ScalarMultiplyBy(e) / (n.GetNorm() * e.GetNorm()));
    }

    new_coord.a_ = 1 / (2 / r.GetNorm() - (v.GetNorm() * v.GetNorm()) / m);
    return new_coord;
}

CartesianCoordinates Keplerian_to_Cartesian(const KeplerianCoordenates& coord)
{
    CartesianCoordinates new_coord;
    double p = coord.a_ * (1 - coord.e_ * coord.e_);
    double m = 398600.4415;
    double C = sqrt(p * m);
    double r = p / (1 + coord.e_ * cos(coord.v_));
    double u = coord.v_ + coord.w_;

    new_coord.x_ = r * (cos(u) * cos(coord.n_) - sin(u) * sin(coord.n_) * cos(coord.i_));
    new_coord.y_ = r * (cos(u) * sin(coord.n_) + sin(u) * cos(coord.n_) * cos(coord.i_));
    new_coord.z_ = r * sin(u) * sin(coord.i_);
    new_coord.vx_ = (C / p) * (coord.e_ * sin(coord.v_) * (cos(u) * cos(coord.n_) - sin(u) * sin(coord.n_) * cos(coord.i_)) +
                               (1 + coord.e_ * cos(coord.v_)) * (-sin(u) * cos(coord.n_) - sin(u) * sin(coord.n_) * cos(coord.i_)));
    new_coord.vy_ = (C / p) * (coord.e_ * sin(coord.v_) * (cos(u) * sin(coord.n_) + sin(u) * cos(coord.n_) * cos(coord.i_)) +
                               (1 + coord.e_ * cos(coord.v_)) * (-sin(u) * sin(coord.n_) + cos(u) * cos(coord.n_) * cos(coord.i_)));
    new_coord.vz_ = (C / p) * (coord.e_ * sin(coord.v_) * sin(u) * sin(coord.i_) + (1 + coord.e_ * cos(coord.v_)) * cos(u) *
                                                                                   sin(coord.i_));
    return new_coord;
}