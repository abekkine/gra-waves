#include "GraWaves.h"

GraWaves::GraWaves( int numBodies )
{
	initVars();
	// DONE : Reserve [numBodies] for instantiating [universe] object.
	GraWaves::numBodies = numBodies;
}

GraWaves::GraWaves()
{
	initVars();
	// DONE : Reserve a default number of bodies, for instantiating [universe] object.
	GraWaves::numBodies = DEFAULT_NUM_BODIES;
}

GraWaves::~GraWaves()
{
	// DONE : Delete [display] resource.
	delete display;
	// DONE : Delete [universe] resource.
	delete universe;
}

void GraWaves::initVars()
{
	timer = NULL;
	display = NULL;
	quitCondition = false;
	numTicks = 0;
	// DONE : Initialize [universe] to NULL.
	universe = NULL;
}

// DONE : All [Update] methods should accept [double timeStep] as parameter.
void GraWaves::Update( double timeStep )
{
	// DONE : Call [universe] [Update] method.
	universe->Update( timeStep );
}

void GraWaves::Initialize()
{
	timer = new Timer();
	display = new Renderer();

	display->SetScreenSize( 200, 200 );
	display->Init();

	timer->Reset();

	// DONE : Initialize [universe].
	universe = new Universe();
	universe->Initialize( numBodies );
}

// DONE : Remove [ReadKey] method.
// DONE : Remove [GetKey] method.

void GraWaves::Run()
{
	while( not quitCondition )
	{
		numTicks = timer->GetElapsed();
		if( numTicks > 500000 )
		{
			// DONE : [Update] method call should include [timeStep] value as parameter.
			Update( 1.0 );
			timer->Reset();
		}

		display->Update();
		display->PollEvents();

		// DONE : Remove [ReadKey] method call.

		quitCondition = display->CheckQuit();
	}
}

