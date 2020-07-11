#include "PowerMethodForGraphVisualization.h"


const int PowerMethod::constFigureMass = 75000;
std::vector<std::pair<double, double> > PowerMethod::pointsOffset;

double Distantion (Point& a, Point& b) {

	double distantion = sqrt((a.X - b.X) * (a.X - b.X) +
						     (a.Y - b.Y) * (a.Y - b.Y));
		
	return distantion;
}


void PowerMethod::PowerMethodIteration(ObjectVector& objects)
{
	pointsOffset.clear();
	pointsOffset.resize(objects.size(), { 0, 0 });

	PushingAwayPoints(objects);
	GravityPoints(objects);

	MovePoints(objects);
}

void PowerMethod::PushingAwayPoints(ObjectVector& objects)
{
	for (size_t i = 0; i < objects.size(); i++) if (objects[i]->GetType() != Figure::Type::Line) {
		for (size_t j = 0; j < objects.size(); j++) if (objects[j]->GetType() != Figure::Type::Line && i != j) {

			FigurePtr figure1 = objects[i];
			FigurePtr figure2 = objects[j];

			Point a = figure1->GetPosition();
			Point b = figure2->GetPosition();

			double distantion = Distantion(a, b);
			double fraction = PowerMethod::constFigureMass / distantion / distantion;

			pointsOffset[i].first += (a.X - b.X) / distantion * fraction / 2;
			pointsOffset[i].second += (a.Y - b.Y) / distantion * fraction / 2;

		}
	}
}

void PowerMethod::GravityPoints(ObjectVector& objects)
{
	
	for (size_t i = 0; i < objects.size(); i++)  if (objects[i]->GetType() != Figure::Type::Line) {

		auto vectorOfLines = objects[i]->GetVectorOfLines();

		for (size_t j = 0; j < vectorOfLines.size(); j++) {
				
			FigurePtr figure1 = objects[i];
			FigurePtr figure2 = vectorOfLines[j].second == 0 ? vectorOfLines[j].first->GetFigure2() : vectorOfLines[j].first->GetFigure1();

			Point a = figure1->GetPosition();
			Point b = figure2->GetPosition();

			double distantion = Distantion(a, b);
			double fraction = (distantion - len * 2);

			pointsOffset[i].first += (b.X - a.X) / distantion * fraction / 2;
			pointsOffset[i].second += (b.Y - a.Y) / distantion * fraction / 2;
		}
	}
	
}

void PowerMethod::MovePoints(ObjectVector& objects)
{
	for (int i = 0; i < pointsOffset.size(); i++) pointsOffset[i].first /= 10, pointsOffset[i].second /= 10;

	for (size_t i = 0; i < objects.size(); i++)  if (objects[i]->GetType() != Figure::Type::Line) {
		
		Point position = objects[i]->GetPosition();

		position.X += (int)pointsOffset[i].first;
		position.Y += (int)pointsOffset[i].second;

		objects[i]->SetPosition(position);
	}
}
