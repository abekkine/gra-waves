#ifndef VECTOR_H
#define VECTOR_H

typedef double Scalar;

class Vector 
{
public:
	Vector();
	Vector( double x, double y, double z );
	// DONE : Implement either [Set] method or overload '=' operator.
	void Set( double x, double y, double z );
	~Vector();

	double x;
	double y;
	double z;
};

#endif

