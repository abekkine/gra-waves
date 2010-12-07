#ifndef GRAWAVES_H
#define GRAWAVES_H

#include <vector>
#include <Timer.h>
#include <Config.h>
#include <Renderer.h>
#include <Universe.h>

#define DEFAULT_NUM_BODIES 10

using namespace std;

class GraWaves
{
	public:
		GraWaves();
		GraWaves( int numBodies );
		~GraWaves();
		void Update( double timeStep );
		void Initialize();
		void Run();
		// DONE : remove key input related methods.

	private:
		int numBodies;
        Config *config;
		Universe *universe;
		Renderer *display;
		// DONE : remove key input related variables.
		bool quitCondition;
		unsigned int numTicks;
        unsigned int ticksPeriod;
		Timer *timer;
		void initVars();
};

#endif

