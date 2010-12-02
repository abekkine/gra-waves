#ifndef BODY_H
#define BODY_H

#include <Entity.h>

class Body : public Entity {

public:
	Body();
	~Body();
	void Update();

private:
	void initVars();
};

#endif

