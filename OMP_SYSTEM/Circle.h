#pragma once

#include "Figure.h"

class Circle
	: public Figure
{

public:

	explicit Circle(const Type type);
	virtual ~Circle();

	void Draw(System::Drawing::Graphics^ graphics, Color color = Color::Black) override;

	System::Drawing::Point GetCenter() override;

private:

	 Circle() = delete;

};