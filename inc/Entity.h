#ifndef ENTITY_H
#define ENTITY_H

#include <Vector.h>
#include <Point.h>

class Entity : public Point 
{
public:
	Entity();
	~Entity();

private:
	unsigned int id;
	Vector acceleration;
	Vector velocity; 
	Scalar mass;

	void initVars();
};

#endif

