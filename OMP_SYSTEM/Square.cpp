#include "Square.h"

Square::Square(const Type type)
	: Figure(type)
{

}

Square::~Square()
{
}


void Square::Draw(System::Drawing::Graphics^ graphics, Color color)
{
	graphics->DrawRectangle(gcnew System::Drawing::Pen(color), _position.X, _position.Y, len, len);
}

Point Square::GetCenter()
{
	return _position;
}