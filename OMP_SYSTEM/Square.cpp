#include "Square.h"

Square::Square(const Type type)
	: Figure(type)
{

}

Square::~Square()
{
}


void Square::Draw(System::Drawing::Graphics^ graphics)
{
	graphics->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Black), _position.X, _position.Y, len, len);
}

Point Square::GetCenter()
{
	return _position;
}