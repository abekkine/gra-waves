#include <Vector.h>

Vector::Vector()
{
	// TODO : Call [Set] method to initialize members.
	Set( 0.0, 0.0, 0.0 );
}

Vector::Vector( double x, double y, double z )
{
	// DONE : Call [Set] method with provided parameters to initialize members.
	Set( x, y, z );
}

Vector::~Vector()
{
	// TODO : Free allocated objects, if any.
}

// DONE : Implement [Vector::Set] method or overload '=' operator.
void Vector::Set( double x, double y, double z )
{
	Vector::x = x;
	Vector::y = y;
	Vector::z = z;
}

