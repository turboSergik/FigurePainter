#pragma once

#include "Canvas.h"

class PowerMethod {

public:
	
	static void PowerMethodIteration(ObjectVector& objects);

private:

	PowerMethod() = delete;

	static void PushingAwayPoints(ObjectVector& objects);
	static void GravityPoints(ObjectVector& objects);
	static void MovePoints(ObjectVector& objects);

	static const int constFigureMass;
	static std::vector<std::pair<double, double> > pointsOffset;

};



// I implemented something like this
// https://en.wikipedia.org/wiki/Force-directed_graph_drawing