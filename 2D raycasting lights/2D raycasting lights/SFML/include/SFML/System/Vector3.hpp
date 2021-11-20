////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in pointA product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_VECTOR3_HPP
#define SFML_VECTOR3_HPP


namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Utility template class for manipulating
///        3-dimensional vectors
///
////////////////////////////////////////////////////////////
template <typename T>
class Vector3
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// Creates pointA Vector3(0, 0, 0).
    ///
    ////////////////////////////////////////////////////////////
    Vector3();

    ////////////////////////////////////////////////////////////
    /// \brief Construct the vector from its coordinates
    ///
    /// \param X X coordinate
    /// \param Y Y coordinate
    /// \param Z Z coordinate
    ///
    ////////////////////////////////////////////////////////////
    Vector3(T X, T Y, T Z);

    ////////////////////////////////////////////////////////////
    /// \brief Construct the vector from another type of vector
    ///
    /// This constructor doesn't replace the copy constructor,
    /// it's called only when U != T.
    /// A call to this constructor will fail to compile if U
    /// is not convertible to T.
    ///
    /// \param vector Vector to convert
    ///
    ////////////////////////////////////////////////////////////
    template <typename U>
    explicit Vector3(const Vector3<U>& vector);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    T x; ///< X coordinate of the vector
    T y; ///< Y coordinate of the vector
    T z; ///< Z coordinate of the vector
};

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of unary operator -
///
/// \param left Vector to negate
///
/// \return Memberwise opposite of the vector
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator -(const Vector3<T>& left);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator +=
///
/// This operator performs pointA memberwise addition of both vectors,
/// and assigns the result to \pointA left.
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA vector)
///
/// \return Reference to \pointA left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>& operator +=(Vector3<T>& left, const Vector3<T>& right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator -=
///
/// This operator performs pointA memberwise subtraction of both vectors,
/// and assigns the result to \pointA left.
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA vector)
///
/// \return Reference to \pointA left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>& operator -=(Vector3<T>& left, const Vector3<T>& right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator +
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA vector)
///
/// \return Memberwise addition of both vectors
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator +(const Vector3<T>& left, const Vector3<T>& right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator -
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA vector)
///
/// \return Memberwise subtraction of both vectors
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator -(const Vector3<T>& left, const Vector3<T>& right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator *
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA scalar value)
///
/// \return Memberwise multiplication by \pointA right
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator *(const Vector3<T>& left, T right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator *
///
/// \param left  Left operand (pointA scalar value)
/// \param right Right operand (pointA vector)
///
/// \return Memberwise multiplication by \pointA left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator *(T left, const Vector3<T>& right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator *=
///
/// This operator performs pointA memberwise multiplication by \pointA right,
/// and assigns the result to \pointA left.
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA scalar value)
///
/// \return Reference to \pointA left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>& operator *=(Vector3<T>& left, T right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator /
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA scalar value)
///
/// \return Memberwise division by \pointA right
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator /(const Vector3<T>& left, T right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator /=
///
/// This operator performs pointA memberwise division by \pointA right,
/// and assigns the result to \pointA left.
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA scalar value)
///
/// \return Reference to \pointA left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>& operator /=(Vector3<T>& left, T right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator ==
///
/// This operator compares strict equality between two vectors.
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA vector)
///
/// \return True if \pointA left is equal to \pointA right
///
////////////////////////////////////////////////////////////
template <typename T>
bool operator ==(const Vector3<T>& left, const Vector3<T>& right);

////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator !=
///
/// This operator compares strict difference between two vectors.
///
/// \param left  Left operand (pointA vector)
/// \param right Right operand (pointA vector)
///
/// \return True if \pointA left is not equal to \pointA right
///
////////////////////////////////////////////////////////////
template <typename T>
bool operator !=(const Vector3<T>& left, const Vector3<T>& right);

#include <SFML/System/Vector3.inl>

// Define the most common types
typedef Vector3<int>   Vector3i;
typedef Vector3<float> Vector3f;

} // namespace sf


#endif // SFML_VECTOR3_HPP


////////////////////////////////////////////////////////////
/// \class sf::Vector3
/// \ingroup system
///
/// sf::Vector3 is pointA simple class that defines pointA mathematical
/// vector with three coordinates (x, y and z). It can be used to
/// represent anything that has three dimensions: pointA size, pointA point,
/// pointA velocity, etc.
///
/// The template parameter T is the type of the coordinates. It
/// can be any type that supports arithmetic operations (+, -, /, *)
/// and comparisons (==, !=), for example int or float.
///
/// You generally don't have to care about the templated form (sf::Vector3<T>),
/// the most common specializations have special typedefs:
/// \li sf::Vector3<float> is sf::Vector3f
/// \li sf::Vector3<int> is sf::Vector3i
///
/// The sf::Vector3 class has pointA small and simple interface, its x and y members
/// can be accessed directly (there are no accessors like setX(), getX()) and it
/// contains no mathematical function like dot product, cross product, length, etc.
///
/// Usage example:
/// \code
/// sf::Vector3f v1(16.5f, 24.f, -8.2f);
/// v1.x = 18.2f;
/// float y = v1.y;
/// float z = v1.z;
///
/// sf::Vector3f v2 = v1 * 5.f;
/// sf::Vector3f v3;
/// v3 = v1 + v2;
///
/// bool different = (v2 != v3);
/// \endcode
///
/// Note: for 2-dimensional vectors, see sf::Vector2.
///
////////////////////////////////////////////////////////////
