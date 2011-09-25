/*Template source: Programming Game AI by Example, pp.64-65
    Author: Mat Buckland
    Publisher: Jones & Bartlett Learning; 1 edition (September 30, 2004)
    ISBN-10: 1556220782
    ISBN-13: 978-1556220784
*/

//------------------------------------------------------------------------
//
//  Name:   Vector3D.h
//
//  Desc:   Derivative work from Buckland's Vector2D.h
//
//  Author: (originally)Mat Buckland 2002 (fup@ai-junkie.com)
//
//  Modified by: Nikolas Willingham
//------------------------------------------------------------------------

#ifndef S3VECTOR_H
#define S3VECTOR_H

#include <math.h>
#include <windows.h>
#include <iosfwd>
#include <limits>

using namespace std;

struct Vector3D
{
 double x, y, z;

 Vector3D():x(0.0),y(0.0),z(0.0){}
 Vector3D(double a, double b, double c):x(a),y(b),z(c){}

 //sets axes to zero
 void Zero()
 {
  x = 0.0;
  y = 0.0;
  z = 0.0;
 }


 //returns length of vector
 inline double Length()const;

 //returns squared length of vector to avoid sqrt
 inline double LengthSq()const;
 inline void Normalize();
 inline double Dot(const Vector3D& v3)const;


 //returns distance between this vector and one passed as parameter
 inline double Distance(const Vector3D &v3)const;

 //squared of above
 inline double DistanceSq(const Vector3D &v3)const;

 //returns reverse vector of this one
 inline Vector3D GetReverse()const;

 //overloaded operators
 const Vector3D& operator+=(const Vector3D &rhs)
 {
  x += rhs.x;
  y += rhs.y;
  z += rhs.z;

  return *this;
 }

 const Vector3D& operator-=(const Vector3D &rhs)
 {
  x -= rhs.x;
  y -= rhs.y;
  z -= rhs.z;

  return *this;
 }

 const Vector3D& operator*=(const Vector3D &rhs)
 {
  x *= rhs.x;
  y *= rhs.y;
  z *= rhs.z;

  return *this;
 }

 const Vector3D& operator/=(const Vector3D &rhs)
 {
  x /= rhs.x;
  y /= rhs.y;
  z /= rhs.z;

  return *this;
 }

 bool operator==(const Vector3D& rhs)const
 {
    return (x == rhs.x && y == rhs.y && z == rhs.z);
 }

 bool operator!=(const Vector3D& rhs)const
 {
    return (x != rhs.x || y != rhs.y || z != rhs.z);
 }
};

//other overloaded operators
inline Vector3D operator*(const Vector3D &lhs, double rhs);
inline Vector3D operator*(double lhs, const Vector3D &rhs);
inline Vector3D operator-(const Vector3D &lhs, const Vector3D &rhs);
inline Vector3D operator+(const Vector3D &lhs, const Vector3D &rhs);
inline Vector3D operator/(const Vector3D &lhs, double val);
std::ostream& operator<<(std::ostream& os, const Vector3D& rhs);
std::ifstream& operator>>(std::ifstream& is, Vector3D& lhs);

//methods

//returns length of 3D vector
inline double Vector3D::Length()const
{
 return sqrt(x*x + y*y + z*z);
}

//returns length squared
inline double Vector3D::LengthSq()const
{
  return (x*x + y*y + z*z);
}

//dot product
inline double Vector3D::Dot(const Vector3D &v3)const
{
  return x*v3.x + y*v3.y + z*v3.z;
}


//Euclidean distance
inline double Vector3D::Distance(const Vector3D &v3)const
{
  double ySeparation = v3.y - y;
  double xSeparation = v3.x - x;
  double zSeparation = v3.z - z;

  return sqrt(ySeparation*ySeparation + xSeparation*xSeparation + zSeparation*zSeparation);
}

//Distance squared
inline double Vector3D::DistanceSq(const Vector3D &v3)const
{
  double ySeparation = v3.y - y;
  double xSeparation = v3.x - x;
  double zSeparation = v3.z - z;

  return ySeparation*ySeparation + xSeparation*xSeparation + zSeparation*zSeparation;
}

//returns reverse vector
inline Vector3D Vector3D::GetReverse()const
{
  return Vector3D(-this->x, -this->y, -this->z);
}

//normalize vector
inline void Vector3D::Normalize()
{ 
  double vector_length = this->Length();

  if (vector_length > std::numeric_limits<double>::epsilon())
  {
    this->x /= vector_length;
    this->y /= vector_length;
	this->z /= vector_length;
  }
}


//overload the - operator
inline Vector3D operator-(const Vector3D &lhs, const Vector3D &rhs)
{
  Vector3D result(lhs);
  result.x -= rhs.x;
  result.y -= rhs.y;
  result.y -= rhs.z;
  return result;
}

//overload the + operator
inline Vector3D operator+(const Vector3D &lhs, const Vector3D &rhs)
{
  Vector3D result(lhs);
  result.x += rhs.x;
  result.y += rhs.y;
  result.z += rhs.z;
  
  return result;
}

//overload the / operator
inline Vector3D operator/(const Vector3D &lhs, double val)
{
  Vector3D result(lhs);
  result.x /= val;
  result.y /= val;
  result.z /= val;

  return result;
}

//non-member functions
inline Vector3D Vec3DNormalize(const Vector3D &v)
{
  Vector3D vec = v;

  double vector_length = vec.Length();

  if (vector_length > std::numeric_limits<double>::epsilon())
  {
    vec.x /= vector_length;
    vec.y /= vector_length;
	vec.z /= vector_length;
  }

  return vec;
}


inline double Vec3DDistance(const Vector3D &v1, const Vector3D &v2)
{

  double ySeparation = v2.y - v1.y;
  double xSeparation = v2.x - v1.x;
  double zSeparation = v2.z - v1.z;

  return sqrt(ySeparation*ySeparation + xSeparation*xSeparation + zSeparation*zSeparation);
}

inline double Vec3DDistanceSq(const Vector3D &v1, const Vector3D &v2)
{

  double ySeparation = v2.y - v1.y;
  double xSeparation = v2.x - v1.x;
  double zSeparation = v2.z - v1.z;

  return ySeparation*ySeparation + xSeparation*xSeparation + zSeparation*zSeparation;
}

inline double Vec3DLength(const Vector3D& v)
{
  return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

inline double Vec3DLengthSq(const Vector3D& v)
{
  return (v.x*v.x + v.y*v.y + v.z*v.z);
}


#endif