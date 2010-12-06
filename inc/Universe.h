#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <map>
#include <vector>
#include <Wave.h>

#define UNIVERSE_RADIUS 1000.0
#define GRAVITY_COEF 1.0

using namespace std;

typedef struct
{
	unsigned int numBodies;
	unsigned int numWaves;
	Scalar age;

} StatsType;

typedef vector< Body * > BodyVectorType;
typedef vector< Wave * > WaveVectorType;

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
	void DumpStats();

private:
	const Scalar conGravity;
	// Radius of the universe; needed for body insertion.
	Scalar radius;
	int numBodies;
	// DONE : Rename conSize to [conLifetime] and move into Wave class.
	// DONE : Rename age variable to [time].
	// DONE : Change type of variable to 'double'.
	double time;

	// DONE : Add a storage variable to store bodies.
	BodyVectorType bodies;
	WaveVectorType waves;

	// Collect stats.
	StatsType stats;

	void initVars();
	void GetWavesCoveringBody( Body* body, WaveVectorType& waves );
	void EliminateOlderWaves( WaveVectorType& waves );
	Vector ComputeAccelerationVector( Body* body, WaveVectorType& waves );		
	Vector GetNewtonianGravity( Body* body, Wave* wave );
};

#endif

