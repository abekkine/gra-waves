#include "GraWaves.h"

GraWaves::GraWaves( int node_id )
{
	initVars();
	// DONE : 
}

GraWaves::GraWaves()
{
	initVars();
	// DONE :
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
	int keyCode = -1;

	keyCode = GetKey();

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

// TODO : Remove [ReadKey] method.
void GraWaves::ReadKey()
{
	static int lastKey = -1;
	keyCode = display->GetKey();

	if( keyCode != -1 )
	{
		if( ! keyQueue.empty() )
		{
			lastKey = keyQueue.back();
		}

		if( lastKey != keyCode )
		{
			keyQueue.push_back( keyCode );
		}

		lastKey = keyCode;
	}
}

// TODO : Remove [GetKey] method.
int GraWaves::GetKey()
{
	int key = -1;
	std::vector< int >::iterator first;

	if( ! keyQueue.empty() )
	{
		first = keyQueue.begin();
		key = *first;
		keyQueue.erase( first );
	}

	return key;
}

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

		// TODO : Remove [ReadKey] method call.
		ReadKey();

		quitCondition = display->CheckQuit();
	}
}

