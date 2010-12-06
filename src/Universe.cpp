#include <Universe.h>

Universe::Universe() : conGravity( GRAVITY_COEF )
{
	// DONE : Constant member [conSize] should be removed from this class.
	initVars();
}

Universe::Universe( Scalar radius ) : conGravity( GRAVITY_COEF )
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
	WaveVectorType::iterator iWave;
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
	BodyVectorType::iterator iBody;
	for( iBody=bodies.begin(); iBody!=bodies.end(); ++iBody )
	{
		(*iBody)->Update( timeStep );

		// DONE : Initiate a new wave for new position of each body.
		Wave *new_wave = new Wave( *iBody );
		waves.push_back( new_wave );
	}

	WaveVectorType waveList;	
	Body *theBody;
	Vector bodyAcceleration;
	for( iBody=bodies.begin(); iBody!=bodies.end(); ++iBody )
	{
		theBody = *iBody;
		
		// DONE : Extract list of waves.
		GetWavesCoveringBody( theBody, waveList );

		// DONE : Eliminate older waves from multiple coverings.
		EliminateOlderWaves( waveList );

		// DONE : Calculate combined acceleration vector.
		bodyAcceleration = ComputeAccelerationVector( theBody, waveList );

		// DONE : Set [body] acceleration vector.
		theBody->SetAcceleration( bodyAcceleration );
	}
}

// DONE : Universe::Initialize( n ) method should be initialized.
void Universe::Initialize( int numBodies )
{
	Universe::numBodies = numBodies;

	// TODO : Inject all bodies into universe.

	// TODO : Inject all waves into universe.
}

void Universe::GetWavesCoveringBody( Body* body, WaveVectorType& waveList )
{
	Wave *theWave;

	// Clean up wave list.
	waveList.clear();

	// Iterate over master wave list.
	WaveVectorType::iterator iWave;
	for( iWave=waves.begin(); iWave!=waves.end(); ++iWave )
	{
		theWave = *iWave;
		if( body->Identifier() != theWave->Source() )
		{
			if( theWave->Covers( body ) )
			{
				waveList.push_back( theWave );
			}
		}
	}
}

void Universe::EliminateOlderWaves( WaveVectorType& waveList )
{
	map< unsigned int, Wave * > waveMap;
	WaveVectorType::iterator iWave;
	Wave *theWave;

	for( iWave=waveList.begin(); iWave!=waveList.end(); ++iWave )
	{
		theWave = *iWave;
		if( waveMap.find( theWave->Source() ) == waveMap.end() )
		{
			// wave of source does not exist in the map, so insert it.
			waveMap[ theWave->Source() ] = theWave;
		}
		else
		{
			// wave of source exists in the map, so replace it if new one has smaller age.
			if( theWave->Age() < waveMap[ theWave->Source() ]->Age() )
			{
				waveMap[ theWave->Source() ] = theWave;
			}
		}
	}

	// Cleanup waveList and transfer contents of waveMap into waveList.
	waveList.clear();
	map< unsigned int, Wave * >::iterator iter;
	for( iter=waveMap.begin(); iter!=waveMap.end(); ++iter )
	{
		waveList.push_back( iter->second );
	}
}

Vector Universe::ComputeAccelerationVector( Body* body, WaveVectorType& waveList )
{
	Vector acceleration;
	WaveVectorType::iterator iWave;
	Wave *theWave;
	
	acceleration.Set( 0.0, 0.0, 0.0 );
	for( iWave=waveList.begin(); iWave!=waveList.end(); ++iWave )
	{
		theWave = *iWave;

		acceleration = acceleration + GetNewtonianGravity( body, theWave );
	}

	return acceleration;
}

Vector Universe::GetNewtonianGravity( Body* body, Wave* wave )
{
	Vector gravityVector;
	Vector distanceVector;
	Scalar distance;
	Scalar squareDistance;
	Scalar gravityForce;

	distanceVector = wave->GetCenter() - body->GetPosition();
	distance = ~distanceVector;
	squareDistance = distance * distance;

	gravityForce = Universe::conGravity * wave->Mass() / squareDistance;

	gravityVector = (!distanceVector) * gravityForce;

	return gravityVector;
}

