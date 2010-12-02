#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <Wave.h>

#define UNIVERSE_SIZE 100

using namespace std;

class Universe
{
public:
	Universe();
	~Universe();

private:
	const int conSize;
	unsigned int age;

	vector< Wave * > waves;

	void initVars();

};

#endif

