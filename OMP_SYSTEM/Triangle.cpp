#include "Triangle.h"

Triangle::Triangle(const Type type)
	: Figure(type)
{

}

Triangle::~Triangle()
{
}


void Triangle::Draw(System::Drawing::Graphics^ graphics)
{
	Point centerPoint = _position;

	centerPoint.X = _position.X + len / 2;
	centerPoint.Y = _position.Y + len / 2;

	Point a1(centerPoint.X, centerPoint.Y - len / 2);
	Point a2(centerPoint.X - len / 2, centerPoint.Y + len / 2);
	Point a3(centerPoint.X + len / 2, centerPoint.Y + len / 2);
	
	graphics->DrawLine(gcnew System::Drawing::Pen(System::Drawing::Color::Black), a1, a2);
	graphics->DrawLine(gcnew System::Drawing::Pen(System::Drawing::Color::Black), a1, a3);
	graphics->DrawLine(gcnew System::Drawing::Pen(System::Drawing::Color::Black), a2, a3);

}

Point Triangle::GetCenter()
{
	return _position;
}