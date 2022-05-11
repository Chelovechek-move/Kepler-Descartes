//
// Created by Chiniaev on 10.05.2022.
//

#include "vector3.hpp"
#include <cmath>

Vector3::Vector3() = default;
Vector3::Vector3(const double &new_v1, const double &new_v2, const double &new_v3) : v1_(new_v1), v2_(new_v2), v3_(new_v3) {}

[[nodiscard]] double Vector3::GetV1() const {
    return v1_;
}
[[nodiscard]] double Vector3::GetV2() const {
    return v2_;
}
[[nodiscard]] double Vector3::GetV3() const {
    return v3_;
}

[[nodiscard]] double Vector3::GetNorm() const {
    return sqrt(v1_ * v1_ + v2_ * v2_ + v3_ * v3_);
}

[[nodiscard]] double Vector3::ScalarMultiplyBy(const Vector3& right_vector) const {
    return v1_ * right_vector.v1_ + v2_ * right_vector.v2_ + v3_ * right_vector.v3_;
}
[[nodiscard]] Vector3 Vector3::VectorMultiplyBy(const Vector3& right_vector) const {
    return {v2_ * right_vector.v3_ - v3_ * right_vector.v2_,
            v3_ * right_vector.v1_ - v1_ * right_vector.v3_,
            v1_ * right_vector.v2_ - v2_ * right_vector.v1_};
}

Vector3 Vector3::operator/(const double& value) const {
    return {v1_ / value, v2_ / value, v3_ / value};
}
Vector3 Vector3::operator-(const Vector3& right_vector) const {
    return {v1_ - right_vector.v1_, v2_ - right_vector.v2_, v3_ - right_vector.v3_};
}