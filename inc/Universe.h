#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <Wave.h>

#define UNIVERSE_RADIUS 1000.0

using namespace std;

class Universe
{
public:
	Universe();
	Universe( Scalar radius );
	~Universe();

	// DONE : All [Update] methods should accept [double timeStep] as parameter.
	void Update( double timeStep );
	// DONE : Add number of bodies as a parameter to [Initialize] method.
	void Initialize( int numBodies );

private:
	// Radius of the universe; needed for body insertion.
	Scalar radius;
	int numBodies;
	// DONE : Rename conSize to [conLifetime] and move into Wave class.
	// DONE : Rename age variable to [time].
	// DONE : Change type of variable to 'double'.
	double time;

	// DONE : Add a storage variable to store bodies.
	vector< Body * > bodies;
	vector< Wave * > waves;

	void initVars();
};

#endif

