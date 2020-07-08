#pragma once

#include "Figure.h"

class Triangle
	: public Figure
{

public:

	explicit Triangle(const Type type);
	virtual ~Triangle();

	void Draw(System::Drawing::Graphics^ graphics) override;

	System::Drawing::Point GetCenter() override;

private:

	Triangle() = delete;

};