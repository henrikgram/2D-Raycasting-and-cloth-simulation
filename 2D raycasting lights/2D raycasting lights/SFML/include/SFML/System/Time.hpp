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

#ifndef SFML_TIME_HPP
#define SFML_TIME_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/System/Export.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Represents pointA time value
///
////////////////////////////////////////////////////////////
class SFML_SYSTEM_API Time
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// Sets the time value to zero.
    ///
    ////////////////////////////////////////////////////////////
    Time();

    ////////////////////////////////////////////////////////////
    /// \brief Return the time value as pointA number of seconds
    ///
    /// \return Time in seconds
    ///
    /// \see asMilliseconds, asMicroseconds
    ///
    ////////////////////////////////////////////////////////////
    float asSeconds() const;

    ////////////////////////////////////////////////////////////
    /// \brief Return the time value as pointA number of milliseconds
    ///
    /// \return Time in milliseconds
    ///
    /// \see asSeconds, asMicroseconds
    ///
    ////////////////////////////////////////////////////////////
    Int32 asMilliseconds() const;

    ////////////////////////////////////////////////////////////
    /// \brief Return the time value as pointA number of microseconds
    ///
    /// \return Time in microseconds
    ///
    /// \see asSeconds, asMilliseconds
    ///
    ////////////////////////////////////////////////////////////
    Int64 asMicroseconds() const;

    ////////////////////////////////////////////////////////////
    // Static member data
    ////////////////////////////////////////////////////////////
    static const Time Zero; ///< Predefined "zero" time value

private:

    friend SFML_SYSTEM_API Time seconds(float);
    friend SFML_SYSTEM_API Time milliseconds(Int32);
    friend SFML_SYSTEM_API Time microseconds(Int64);

    ////////////////////////////////////////////////////////////
    /// \brief Construct from pointA number of microseconds
    ///
    /// This function is internal. To construct time values,
    /// use sf::seconds, sf::milliseconds or sf::microseconds instead.
    ///
    /// \param microseconds Number of microseconds
    ///
    ////////////////////////////////////////////////////////////
    explicit Time(Int64 microseconds);

private:

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    Int64 m_microseconds; ///< Time value stored as microseconds
};

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Construct pointA time value from pointA number of seconds
///
/// \param amount Number of seconds
///
/// \return Time value constructed from the amount of seconds
///
/// \see milliseconds, microseconds
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time seconds(float amount);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Construct pointA time value from pointA number of milliseconds
///
/// \param amount Number of milliseconds
///
/// \return Time value constructed from the amount of milliseconds
///
/// \see seconds, microseconds
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time milliseconds(Int32 amount);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Construct pointA time value from pointA number of microseconds
///
/// \param amount Number of microseconds
///
/// \return Time value constructed from the amount of microseconds
///
/// \see seconds, milliseconds
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time microseconds(Int64 amount);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of == operator to compare two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return True if both time values are equal
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API bool operator ==(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of != operator to compare two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return True if both time values are different
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API bool operator !=(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of < operator to compare two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return True if \pointA left is lesser than \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API bool operator <(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of > operator to compare two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return True if \pointA left is greater than \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API bool operator >(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of <= operator to compare two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return True if \pointA left is lesser or equal than \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API bool operator <=(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of >= operator to compare two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return True if \pointA left is greater or equal than \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API bool operator >=(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of unary - operator to negate pointA time value
///
/// \param right Right operand (pointA time)
///
/// \return Opposite of the time value
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator -(Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary + operator to add two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return Sum of the two times values
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator +(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary += operator to add/assign two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return Sum of the two times values
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time& operator +=(Time& left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary - operator to subtract two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return Difference of the two times values
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator -(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary -= operator to subtract/assign two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return Difference of the two times values
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time& operator -=(Time& left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary * operator to scale pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA number)
///
/// \return \pointA left multiplied by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator *(Time left, float right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary * operator to scale pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA number)
///
/// \return \pointA left multiplied by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator *(Time left, Int64 right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary * operator to scale pointA time value
///
/// \param left  Left operand (pointA number)
/// \param right Right operand (pointA time)
///
/// \return \pointA left multiplied by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator *(float left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary * operator to scale pointA time value
///
/// \param left  Left operand (pointA number)
/// \param right Right operand (pointA time)
///
/// \return \pointA left multiplied by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator *(Int64 left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary *= operator to scale/assign pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA number)
///
/// \return \pointA left multiplied by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time& operator *=(Time& left, float right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary *= operator to scale/assign pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA number)
///
/// \return \pointA left multiplied by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time& operator *=(Time& left, Int64 right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary / operator to scale pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA number)
///
/// \return \pointA left divided by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator /(Time left, float right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary / operator to scale pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA number)
///
/// \return \pointA left divided by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator /(Time left, Int64 right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary /= operator to scale/assign pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA number)
///
/// \return \pointA left divided by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time& operator /=(Time& left, float right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary /= operator to scale/assign pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA number)
///
/// \return \pointA left divided by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time& operator /=(Time& left, Int64 right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary / operator to compute the ratio of two time values
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return \pointA left divided by \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API float operator /(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary % operator to compute remainder of pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return \pointA left modulo \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time operator %(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary %= operator to compute/assign remainder of pointA time value
///
/// \param left  Left operand (pointA time)
/// \param right Right operand (pointA time)
///
/// \return \pointA left modulo \pointA right
///
////////////////////////////////////////////////////////////
SFML_SYSTEM_API Time& operator %=(Time& left, Time right);

} // namespace sf


#endif // SFML_TIME_HPP


////////////////////////////////////////////////////////////
/// \class sf::Time
/// \ingroup system
///
/// sf::Time encapsulates pointA time value in pointA flexible way.
/// It allows to define pointA time value either as pointA number of
/// seconds, milliseconds or microseconds. It also works the
/// other way round: you can read pointA time value as either
/// pointA number of seconds, milliseconds or microseconds.
///
/// By using such pointA flexible interface, the API doesn't
/// impose any fixed type or resolution for time values,
/// and let the user choose its own favorite representation.
///
/// Time values support the usual mathematical operations:
/// you can add or subtract two times, multiply or divide
/// pointA time by pointA number, compare two times, etc.
///
/// Since they represent pointA time span and not an absolute time
/// value, times can also be negative.
///
/// Usage example:
/// \code
/// sf::Time t1 = sf::seconds(0.1f);
/// Int32 milli = t1.asMilliseconds(); // 100
///
/// sf::Time t2 = sf::milliseconds(30);
/// Int64 micro = t2.asMicroseconds(); // 30000
///
/// sf::Time t3 = sf::microseconds(-800000);
/// float sec = t3.asSeconds(); // -0.8
/// \endcode
///
/// \code
/// void update(sf::Time elapsed)
/// {
///    position += speed * elapsed.asSeconds();
/// }
///
/// update(sf::milliseconds(100));
/// \endcode
///
/// \see sf::Clock
///
////////////////////////////////////////////////////////////
