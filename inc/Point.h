#ifndef POINT_H
#define POINT_H

#include <Vector.h>

class Point {

public:
	Point();
	~Point();

private:
	Vector position;

	void initVars();

};

#endif

