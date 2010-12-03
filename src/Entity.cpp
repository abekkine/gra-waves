#include <Entity.h>

Entity::Entity()
{
	// DONE : Call [initVars] method.
	initVars();
}

Entity::Entity( unsigned int id )
{
	// DONE : Initialize with id.
	initVars();
	Entity::id = id;
}

Entity::~Entity()
{
	// DONE : Free allocated objects, if any.
}

void Entity::initVars()
{
	// DONE : General initialization of all members.
	id = -1;
	position.Set( 0.0, 0.0, 0.0 );
	acceleration.Set( 0.0, 0.0, 0.0 );
	velocity.Set( 0.0, 0.0, 0.0 );
	mass = DEFAULT_MASS;
}

unsigned int Entity::Identifier()
{
	return id;
}

Scalar Entity::GetMass()
{
	return mass;
}

Vector& Entity::GetPosition()
{
	return position;
}

void Entity::SetAcceleration( double x, double y, double z )
{
	acceleration.x = x;
	acceleration.y = y;
	acceleration.z = z;
}

