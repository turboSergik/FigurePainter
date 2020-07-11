#include "Line.h"

Line::Line(const Type type)
	: Figure(type)
{
}

Line::~Line()
{
}


void Line::Draw(System::Drawing::Graphics^ graphics, Color color)
{
	graphics->DrawLine(gcnew System::Drawing::Pen(color), _position, _position2);
}


Point Line::GetCenter()
{
	return _position;
}

void Line::SetPosition2(const Point point)
{
	_position2 = point;
}

Point Line::GetPosition2() const
{
	return _position2;
}

FigurePtr Line::GetFigure1() const { return _figure1; }

void Line::SetFigure1(const FigurePtr figure) { _figure1 = figure; }


FigurePtr Line::GetFigure2() const { return _figure2; }

void Line::SetFigure2(const FigurePtr figure) { _figure2 = figure; }

