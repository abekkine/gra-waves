#ifndef BODY_H
#define BODY_H

#include <stdlib.h>
#include <vector>
#include <Entity.h>

class Body : public Entity {

public:
    Body( int id );
    ~Body();
    void AtRandom( Scalar radius );
    void Update( double timeStep );

private:
    void initVars();
    double RandomBetween( double min, double max );
};

typedef std::vector< Body * > BodyVectorType;

#endif

