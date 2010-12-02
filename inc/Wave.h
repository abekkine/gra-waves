#ifndef WAVE_H
#define WAVE_H

#include <Point.h>
#include <Vector.h>

#define WAVE_SPEED 1.0

class Wave
{
public:
	Wave();
	Wave( Vector& center );
	Wave *Update();
	~Wave();


private:
	const Scalar conSpeed;
	unsigned int id;
	unsigned int frame;
	Scalar radius;
	Scalar mass;
	Point center;

	void initVars();
	
};

#endif

