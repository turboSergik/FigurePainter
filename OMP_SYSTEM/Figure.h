#pragma once

#include "Forward.hpp"

class Figure 
{
public:

	enum class Type 
	{
		Circle,
		Square, 
		Triangle,
		Line,
	};
	
	explicit Figure(const Type type);
	virtual ~Figure();

	void SetPosition(const Point& position);
	void Move(const Point position);

	const Point& GetPosition() const { return _position; }
	const std::vector<std::pair<LinePtr, bool> >& GetVectorOfLines() const { return _vectorOfLines; }

	void SetColor(const Color color);

	Type GetType() const { return _type; }

	void AddLine(LinePtr line);

	virtual void Draw(System::Drawing::Graphics^ graphics, Color color = Color::Black);
	virtual Point GetCenter();

protected:

	const Type _type;

	System::Drawing::Point _position;

private:

	Figure() = delete;
	Figure& operator=(const Figure&) = delete;

	std::vector<std::pair<LinePtr, bool> > _vectorOfLines;

	// Color _color;
};