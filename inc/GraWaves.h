#ifndef GRAWAVES_H
#define GRAWAVES_H

#include <vector>
#include <Timer.h>
#include <Renderer.h>

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
		void ReadKey();
		int GetKey();

	private:
		Renderer *display;
		int keyCode;
		std::vector< int > keyQueue;
		bool quitCondition;
		unsigned int numTicks;
		Timer *timer;
		void initVars();
};

#endif

