#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <map>
#include <vector>
#include <Wave.h>

using namespace std;

typedef struct
{
    unsigned int numBodies;
    unsigned int numWaves;
    Scalar age;

} StatsType;

class Universe
{
public:
    Universe();
    Universe( Scalar radius );
    ~Universe();

    // DONE : All [Update] methods should accept [double timeStep] as parameter.
    void Update( double timeStep );
    // DONE : Add number of bodies as a parameter to [Initialize] method.
    void Initialize();

    void Radius( Scalar radius );
    void NumBodies( int numBodies );

    BodyVectorType& GetBodies();
    WaveVectorType& GetWaves();
    void DumpStats();
    void DumpEnable( bool enable );

public:
    static Scalar GRAVITY_COEF;

private:
    const Scalar conGravity;
    // Radius of the universe; needed for body insertion.
    Scalar radius;
    int numBodies;
    // DONE : Rename conSize to [conLifetime] and move into Wave class.
    // DONE : Rename age variable to [time].
    // DONE : Change type of variable to 'double'.
    double time;
    bool fDumpEnabled;

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

