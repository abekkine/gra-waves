#include <Body.h>

Body::Body()
{
	// DONE : Method [initVars] should be called.
	initVars();
}

Body::~Body()
{
	// DONE : Any allocated objects should be freed.
}

void Body::initVars()
{
	// DONE : Initialization of member variables should be performed.
	// Nothing to initialize.
}

// DONE : All Update methods should accept [double timeStep] as parameter.
void Body::Update( double timeStep )
{
	// DONE : Velocity should be updated according to [timeStep].
	velocity.x += timeStep * acceleration.x;
	velocity.y += timeStep * acceleration.y;
	velocity.z += timeStep * acceleration.z;

	// DONE : Position should be updated according to [timeStep].
	position.x += timeStep * velocity.x;
	position.y += timeStep * velocity.y;
	position.z += timeStep * velocity.z;
	
}

double Body::RandomBetween( double min, double max )
{
	double range = max - min;
	double root = ((float) rand()) / (float)(RAND_MAX);

	return (min + range*root);
}

void Body::AtRandom( Scalar radius )
{
	position.x = RandomBetween( -radius, radius );
	position.y = RandomBetween( -radius, radius );
	position.z = RandomBetween( -radius, radius );
}

// DONE : Method [SetAcceleration] will be implemented.
