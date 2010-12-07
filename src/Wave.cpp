#include <stdio.h>
#include <Wave.h>

// DONE : Constant [conLifetime] will be initialized.
Wave::Wave():conLifetime( WAVE_LIFE ),conSpeed( WAVE_SPEED )
{
	// DONE : Call [initVars] for general initialization.
	initVars();
}

// DONE : Constructor will use [body] instead of [center].
// DONE : Constant [conLifetime] will be initialized.
Wave::Wave( Body* body ):conLifetime( WAVE_LIFE ),conSpeed( WAVE_SPEED )
{
	// DONE : Call [initVars] for general initialization.
	initVars();
	// DONE : Use [body] reference for special initialization.
	source = body->Identifier();
	mass = body->GetMass();
	center = body->GetPosition();
	radius = 0.0;
	alive = true;
}

Wave::~Wave()
{
	// DONE : cleanup any allocated objects.
}

void Wave::initVars()
{
	// DONE : initialize member variables.
	source = -1;
	mass = 0.0;
	center.Set( 0.0, 0.0, 0.0 );
	radius = 0.0;
	age = 0.0;
	alive = false;
}

// DONE : change to void function.
// DONE : All Update methods should accept [double timeStep] as parameter.
void Wave::Update( double timeStep )
{
	// DONE : check wave age and deactive it if necessary.
	if( age > conLifetime )
	{
		alive = false;
	}
	else
	{
		// DONE : increment wave age.
		age += timeStep;
		// DONE : update wave radius.
		radius += timeStep * conSpeed;
	}
}

// DONE : implement [IsAlive] method.
bool Wave::IsAlive()
{
	return alive;
}

Vector& Wave::GetCenter()
{
	return center;
}

bool Wave::Covers( Body *body )
{
	Vector distance;

	distance = body->GetPosition() - center;

	return (~distance < radius);
}

unsigned int Wave::Source()
{
	return source;
}

Scalar Wave::Age()
{
	return age;
}

Scalar Wave::Mass()
{
	return mass;
}

Scalar Wave::Radius()
{
    return radius;
}

