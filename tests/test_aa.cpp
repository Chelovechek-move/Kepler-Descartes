//
// Created by vladimir on 11.05.22.
//

#include "gtest/gtest.h"
#include "my_project/SlaeBaseException.hpp"
#include "my_project/utility/coordinates.hpp"
#include "my_project/calculations/calculations.hpp"

TEST(Cartesian_to_Keplerian_to_Cartesian, Test1) {
    CartesianCoordinates cart_coord = {1000000., 10., 5., -11., -1., 1.};
    CartesianCoordinates new_cart_coord = Keplerian_to_Cartesian(Cartesian_to_Keplerian(cart_coord));

    double tolerance = 10e-3;
    ASSERT_NEAR(cart_coord.x_, new_cart_coord.x_, tolerance);
    ASSERT_NEAR(cart_coord.y_, new_cart_coord.y_, tolerance);
    ASSERT_NEAR(cart_coord.z_, new_cart_coord.z_, tolerance);
    ASSERT_NEAR(cart_coord.vx_, new_cart_coord.vx_, tolerance);
    ASSERT_NEAR(cart_coord.vx_, new_cart_coord.vx_, tolerance);
    ASSERT_NEAR(cart_coord.vx_, new_cart_coord.vx_, tolerance);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Old Cartesian coordinate x_ = " << cart_coord.x_ << " equals to new Cartesian coordinate x_ = " << new_cart_coord.x_ << std::endl;
    std::cout << "Old Cartesian coordinate y_ = " << cart_coord.y_ << " equals to new Cartesian coordinate y_ = " << new_cart_coord.y_ << std::endl;
    std::cout << "Old Cartesian coordinate z_ = " << cart_coord.z_ << " equals to new Cartesian coordinate z_ = " << new_cart_coord.z_ << std::endl;
    std::cout << "Old Cartesian coordinate vx_ = " << cart_coord.vx_ << " equals to new Cartesian coordinate vx_ = " << new_cart_coord.vx_ << std::endl;
    std::cout << "Old Cartesian coordinate vy_ = " << cart_coord.vy_ << " equals to new Cartesian coordinate vy_ = " << new_cart_coord.vy_ << std::endl;
    std::cout << "Old Cartesian coordinate vz_ = " << cart_coord.vz_ << " equals to new Cartesian coordinate vz_ = " << new_cart_coord.vz_ << std::endl;
}