#ifndef ENTITY_H
#define ENTITY_H

#include <Vector.h>

#define DEFAULT_MASS 100.0

class Entity 
{
public:
	Entity();
	Entity( unsigned int id );
	~Entity();
	unsigned int Identifier();
	Scalar GetMass();
	Vector& GetPosition();
	void SetAcceleration( double x, double y, double z );

protected:
	unsigned int id;
	Vector position;
	Vector acceleration;
	Vector velocity; 
	Scalar mass;

private:
	void initVars();
};

#endif

