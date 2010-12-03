#ifndef GRAWAVES_H
#define GRAWAVES_H

#include <vector>
#include <Timer.h>
#include <Renderer.h>
#include <Universe.h>

using namespace std;

class GraWaves
{
	public:
		GraWaves();
		GraWaves(int node_id);
		~GraWaves();
		void Update();
		void Initialize();
		void Run();
		// TODO : remove key input related methods.
		void ReadKey();
		int GetKey();

	private:
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

