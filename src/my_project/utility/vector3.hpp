//
// Created by Chiniaev on 10.05.2022.
//

#ifndef COMPUTATIONAL_MECHANICS_VECTOR3_HPP
#define COMPUTATIONAL_MECHANICS_VECTOR3_HPP

class Vector3
{
private:
    double v1_ = 0;     // The first component of the vector
    double v2_ = 0;     // The second component of the vector
    double v3_ = 0;     // The third component of the vector

public:
    /** The default constructor of a vector of dimension three
   */
    Vector3();

    /** Constructor of a vector by three coordinates
    *
    * @param new_v1 the first coordinate
    * @param new_v2 the second coordinate
    * @param new_v3 the third coordinate
   */
    Vector3(const double& new_v1, const double& new_v2, const double& new_v3);

    /** Method that returns the first component of the vector
   */
    [[nodiscard]] double GetV1() const;

    /** Method that returns the second component of the vector
   */
    [[nodiscard]] double GetV2() const;

    /** Method that returns the third component of the vector
   */
    [[nodiscard]] double GetV3() const;

    /** Method that returns the norm of the vector
   */
    [[nodiscard]] double GetNorm() const;

    /** A method that returns the result of a scalar product of two vectors
    * @param right_vector the vector to be multiplied by
   */
    [[nodiscard]] double ScalarMultiplyBy(const Vector3& right_vector) const;

    /** A method that returns the result of a vector product of two vectors
    * @param right_vector the right vector in the vector multiplication operation
   */
    [[nodiscard]] Vector3 VectorMultiplyBy(const Vector3& right_vector) const;

    /** The operator of dividing a vector by a number
     *
     * @param value divider
    */
    Vector3 operator/(const double& value) const;

    /** Operator for subtracting one vector from another
     *
     * @param right_vector subtractable vector
    */
    Vector3 operator-(const Vector3& right_vector) const;
};

#endif //COMPUTATIONAL_MECHANICS_VECTOR3_HPP
