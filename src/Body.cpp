#include <stdio.h>
#include <Body.h>

Body::Body( int id )
{
    initVars();
    Body::id = id;
}

Body::~Body()
{
}

void Body::initVars()
{
    // Nothing to initialize.
}

void Body::Update( double timeStep )
{
    velocity.x += timeStep * acceleration.x;
    velocity.y += timeStep * acceleration.y;
    velocity.z += timeStep * acceleration.z;

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

//DEBUG for speeds
	velocity.x = RandomBetween( -0.5, 0.5 );
	velocity.y = RandomBetween( -0.5, 0.5 );
	velocity.z = RandomBetween( -0.5, 0.5 );
//END
}

