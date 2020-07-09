#pragma once

#include "Figure.h"

class Square
	: public Figure
{

public:

	explicit Square(const Type type);
	virtual ~Square();

	void Draw(System::Drawing::Graphics^ graphics, Color color = Color::Black) override;

	System::Drawing::Point GetCenter() override;

private:

	Square() = delete;

};