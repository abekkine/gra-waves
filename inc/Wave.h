#ifndef WAVE_H
#define WAVE_H

#include <Point.h>
#include <Vector.h>

#define WAVE_SPEED 1.0

class Wave
{
public:
	Wave();
	// TODO : Instead of center, use [body] reference to create wave instance.
	Wave( Vector& center );
	// DONE : Wave initialization will be performed in universe, so change method below to void.
	// TODO : All Update methods should accept [double timeStep] as parameter.
	void Update();
	~Wave();
	// TODO : Method [IsAlive] will be added to check wave status.


private:
	// TODO : Constant [conLifetime] added to keep track of wave lifetime.
	// TODO : Member [alive] should be added to indicate wave is active.
	const Scalar conSpeed;
	// TODO : Rename 'id' as [source] to indicate inducing [body] id.
	unsigned int id;
	// TODO : Rename 'frame' to [age], used as sim_time.
	unsigned int frame;
	Scalar radius;
	Scalar mass;
	Point center;

	void initVars();
	
};

#endif

