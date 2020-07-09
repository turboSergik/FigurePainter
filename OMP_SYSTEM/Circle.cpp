#include "Circle.h"

Circle::Circle(const Type type)
	: Figure(type)
{
	
}

Circle::~Circle()
{
}


void Circle::Draw(System::Drawing::Graphics^ graphics, Color color)
{
	graphics->DrawEllipse(gcnew System::Drawing::Pen(color), this->GetCenter().X, this->GetCenter().Y, len, len);
}

Point Circle::GetCenter()
{
	return _position;
}
