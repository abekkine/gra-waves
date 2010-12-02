#include "GraWaves.h"

GraWaves::GraWaves( int node_id )
{
	initVars();
}

GraWaves::GraWaves()
{
	initVars();
}

GraWaves::~GraWaves()
{
}

void GraWaves::initVars()
{
	timer = NULL;
	display = NULL;
	quitCondition = false;
	numTicks = 0;
}

void GraWaves::Update()
{
	int keyCode = -1;

	keyCode = GetKey();
}

void GraWaves::Initialize()
{
	timer = new Timer();
	display = new Renderer();

	display->SetScreenSize( 200, 200 );
	display->Init();

	timer->Reset();
}

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
			Update();
			timer->Reset();
		}

		display->Update();
		display->PollEvents();

		ReadKey();

		quitCondition = display->CheckQuit();
	}
}
