//
// Created by vladimir on 11.05.22.
//

#ifndef MY_PROJECT_CALCULATIONS_HPP
#define MY_PROJECT_CALCULATIONS_HPP

#include "my_project/utility/coordinates.hpp"
#include "my_project/utility/vector3.hpp"

#include "cmath"

/** A function for translating Cartesian coordinates into Keplerian elements of the orbit
*
* @param coord Cartesian coordinates to be converted
*/
KeplerianCoordenates Cartesian_to_Keplerian(const CartesianCoordinates& coord);

/** A function for translating Keplerian elements of the orbit into Cartesian coordinates
*
* @param coord Keplerian coordinates to be converted
*/
CartesianCoordinates Keplerian_to_Cartesian(const KeplerianCoordenates& coord);

#endif //MY_PROJECT_CALCULATIONS_HPP
