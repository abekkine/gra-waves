#ifndef VECTOR_H
#define VECTOR_H

typedef double Scalar;

class Vector 
{
public:
	Vector();
	Vector( double x, double y, double z );
	~Vector();

	double x;
	double y;
	double z;
};

#endif

