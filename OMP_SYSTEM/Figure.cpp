#include "Figure.h"

#include "Line.h"

Figure::Figure(const Type type)
	: _type(type) 
{

}

Figure::~Figure()
{

}

void Figure::SetPosition(const Point& position)
{
	this->Move(position);
	_position = position;
}

void Figure::Move(const Point& position)
{
	Point newPos = position;
	newPos.X += len / 2;
	newPos.Y += len / 2;

	for (auto& object : this->_vectorOfLines) {
		if (object.second == 0) object.first->SetPosition(newPos);
		else object.first->SetPosition2(newPos);
	}
}


void Figure::SetColor(const System::Drawing::Color color)
{
	// _color = color;

	/// Cannot declare a managed object in an unmanaged class 
}

void Figure::AddLine(LinePtr line)
{
	Point center = this->GetCenter();
	
	center.X += len / 2;
	center.Y += len / 2;

	if (center == line->GetPosition()) this->_vectorOfLines.push_back({ line, 0 });
	else this->_vectorOfLines.push_back({ line, 1 });
}

void Figure::Draw(System::Drawing::Graphics^ graphics, Color color)
{
}

System::Drawing::Point Figure::GetCenter()
{
	return System::Drawing::Point(0, 0);
}
