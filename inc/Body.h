#ifndef BODY_H
#define BODY_H

#include <Entity.h>

class Body : public Entity {

public:
	Body();
	~Body();
	// TODO : Method [SetAccelaration] will be declared.
	// TODO : [Update] method should accept [double timeStep] parameter.
	void Update();

private:
	void initVars();
};

#endif

