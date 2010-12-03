#ifndef GRAWAVES_H
#define GRAWAVES_H

#include <vector>
#include <Timer.h>
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
		void Update();
		void Initialize();
		void Run();
		// TODO : remove key input related methods.
		void ReadKey();
		int GetKey();

	private:
		int numBodies;
		Universe *universe;
		Renderer *display;
		// TODO : remove key input related variables.
		int keyCode;
		std::vector< int > keyQueue;
		bool quitCondition;
		unsigned int numTicks;
		Timer *timer;
		void initVars();
};

#endif

