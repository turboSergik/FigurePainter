#pragma once

#include "Figure.h"

class Line
	: public Figure
{

public:

	explicit Line(const Type type);
	virtual ~Line();

	void Draw(System::Drawing::Graphics^ graphics, Color color = Color::Black) override;

	System::Drawing::Point GetCenter() override;

	void SetPosition2(const Point point);
	Point GetPosition2() const;

	void SetFigure1(const FigurePtr figure);
	FigurePtr GetFigure1() const;

	void SetFigure2(const FigurePtr figure);
	FigurePtr GetFigure2() const;

private:

	Line() = delete;

	Point _position2;

	FigurePtr _figure1;
	FigurePtr _figure2;

};