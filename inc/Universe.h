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

	// TODO : All [Update] methods should accept [double timeStep] as parameter.
	void Update();
	// TODO : Add number of bodies as a parameter to [Initialize] method.
	void Initialize();

private:
	// TODO : Rename conSize to [conLifetime] and move into Wave class.
	const int conSize;
	// TODO : Rename age variable to [time].
	// TODO : Change type of variable to 'double'.
	unsigned int age;

	// TODO : Add a storage variable to store bodies.
	vector< Wave * > waves;

	void initVars();

};

#endif

