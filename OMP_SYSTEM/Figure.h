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

	void SetPosition(const System::Drawing::Point& position);
	void Move(const Point& position);

	const System::Drawing::Point& GetPosition() const { return _position; }

	void SetColor(const System::Drawing::Color color);

	Type GetType() const { return _type; }

	void AddLine(LinePtr line);

	virtual void Draw(System::Drawing::Graphics^ graphics);
	virtual System::Drawing::Point GetCenter();

protected:

	const Type _type;

	System::Drawing::Point _position;

private:

	Figure() = delete;
	Figure& operator=(const Figure&) = delete;

	std::vector<std::pair<LinePtr, bool> > _vectorOfLines;

	// Color _color;
};