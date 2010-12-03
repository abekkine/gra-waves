#include <Universe.h>

Universe::Universe()
{
	// DONE : Constant member [conSize] should be removed from this class.
	initVars();
}

Universe::Universe( Scalar radius )
{
	initVars();
	Universe::radius = radius;
}

Universe::~Universe()
{
	// DONE : Free objects in [bodies].
	while( not bodies.empty() )
	{
		Body *aBody = bodies.back();
		bodies.pop_back();
		delete aBody;
	}

	// DONE : Free objects in [waves].
	while( not waves.empty() )
	{
		Wave *aWave = waves.back();
		waves.pop_back();
		delete aWave;
	}
}

void Universe::initVars()
{
	// DONE : All member variables should be reset in this method.
	radius = UNIVERSE_RADIUS;
	numBodies = 0;
	time = 0.0;
	bodies.clear();
	waves.clear();
}

// DONE : Universe::Update() method should be implemented.
// DONE : Universe::Update() method should accept [double timeStep] as parameter.
void Universe::Update( double timeStep )
{
	// DONE : Update all waves.
	// DONE : Discard inactive waves.
	vector< Wave * >::iterator iWave;
	for( iWave=waves.begin(); iWave!=waves.end(); ++iWave )
	{
		if( (*iWave)->IsAlive() )
		{
			(*iWave)->Update( timeStep );
		}
		else
		{
			Wave *deadWave = *iWave;
			bool exitLoop = (deadWave == waves.back());

			waves.erase( iWave );
			delete deadWave;

			if(exitLoop)
			{
				break;
			}
		}
	}

	// DONE : Update all bodies.
	vector< Body * >::iterator iBody;
	for( iBody=bodies.begin(); iBody!=bodies.end(); iBody++ )
	{
		(*iBody)->Update( timeStep );
	}
	

	// TODO : Initiate a new wave.
	// TODO : Extract list of waves.
	// TODO : Eliminate incompatible waves.
	// TODO : Calculate combined acceleration vector.
	// TODO : Set [body] acceleration vector.
}

// DONE : Universe::Initialize( n ) method should be initialized.
void Universe::Initialize( int numBodies )
{
	Universe::numBodies = numBodies;

	// TODO : Inject all bodies into universe.

	// TODO : Inject all waves into universe.
}
