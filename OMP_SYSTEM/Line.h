#pragma once

#include "Figure.h"

class Line
	: public Figure
{

public:

	explicit Line(const Type type);
	virtual ~Line();

	void Draw(System::Drawing::Graphics^ graphics) override;

	System::Drawing::Point GetCenter() override;

	void SetPosition2(const Point point);
	Point GetPosition2() const;

private:

	Line() = delete;

	Point _position2;

};