#include <math.h>
#include <Vector.h>

Vector::Vector()
{
	// DONE : Call [Set] method to initialize members.
	Set( 0.0, 0.0, 0.0 );
}

Vector::Vector( double x, double y, double z )
{
	// DONE : Call [Set] method with provided parameters to initialize members.
	Set( x, y, z );
}

Vector::~Vector()
{
	// DONE : Free allocated objects, if any.
}

// DONE : Implement [Vector::Set] method or overload '=' operator.
void Vector::Set( double x, double y, double z )
{
	Vector::x = x;
	Vector::y = y;
	Vector::z = z;
}

// 1. Assignment
Vector& Vector::operator=(const Vector &rhs)
{
	// DONE : Assignment overload.
	if( this != &rhs )
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}

	return *this;
}

// 2. Addition
Vector Vector::operator+(const Vector &rhs)
{
	// DONE : Addition overload.
	Vector result = *this;

	result.x += rhs.x;
	result.y += rhs.y;
	result.z += rhs.z;

	return result;
}

// 3. Substraction
Vector Vector::operator-(const Vector &rhs)
{
	// DONE : Substraction overload.
	Vector result = *this;

	result.x -= rhs.x;
	result.y -= rhs.y;
	result.z -= rhs.z;

	return result;
}

// 4. Multiplication by a scalar
Vector Vector::operator*(const Scalar &rhs)
{
	Vector result = *this;

	// DONE : Multiply by scalar overload.
	result.x *= rhs;
	result.y *= rhs;
	result.z *= rhs;

	return result;
}

// 5. Division by a scalar
Vector Vector::operator/(const Scalar &rhs)
{
	Vector result = *this;

	// DONE : Divide by scalar overload.
	result.x /= rhs;
	result.y /= rhs;
	result.z /= rhs;

	return result;
}

// 6. Dot product
Scalar Vector::operator|(const Vector &rhs)
{
	// DONE : Dot product overload.
	Scalar result;

	result = (this->x * rhs.x);
	result += (this->y * rhs.y);
	result += (this->z * rhs.z);

	return result;
}

// 7. Cross product
Vector Vector::operator^(const Vector &rhs)
{
	// DONE : Cross product overload.
	Vector result;

	result.x = this->y * rhs.z - this->z * rhs.y;
	result.y = this->z * rhs.x - this->x * rhs.z;
	result.z = this->x * rhs.y - this->y * rhs.x;

	return result;
}

// 8. Magnitude
Scalar Vector::operator~()
{
	// DONE : Magnitude overload.
	return sqrt( this->x*this->x + this->y*this->y + this->z*this->z );
}

// 9. Unit
Vector Vector::operator!()
{
	Vector result = *this;
	Scalar magnitude = ~result;

	// DONE : Unit vector overload.
	result.x /= magnitude;
	result.y /= magnitude;
	result.z /= magnitude;

	return result;
}




