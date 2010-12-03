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
	// TODO : Delete [display] resource.
	// TODO : Delete [universe] resource.
}

void GraWaves::initVars()
{
	timer = NULL;
	display = NULL;
	quitCondition = false;
	numTicks = 0;
	// TODO : Initialize [universe] to NULL.
}

// TODO : All [Update] methods should accept [double timeStep] as parameter.
void GraWaves::Update()
{
	// TODO : Call [universe] [Update] method.
}

void GraWaves::Initialize()
{
	timer = new Timer();
	display = new Renderer();

	display->SetScreenSize( 200, 200 );
	display->Init();

	timer->Reset();

	// TODO : Initialize [universe].
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
			// TODO : [Update] method call should include [timeStep] value as parameter.
			Update();
			timer->Reset();
		}

		display->Update();
		display->PollEvents();

		// DONE : Remove [ReadKey] method call.

		quitCondition = display->CheckQuit();
	}
}

