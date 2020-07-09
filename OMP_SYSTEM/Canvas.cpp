#include "Canvas.h"

#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Line.h"

#include "windows.h"

Canvas::Canvas()
{
}

Canvas* Canvas::_instance = 0;

Canvas* Canvas::GetInstance()
{
	if (_instance == 0)
		_instance = new Canvas();

	return _instance;
}

void Canvas::AddObject(const std::shared_ptr<Figure> object)
{
	_objects.push_back(object);
}

void Canvas::RemoveObject(const Figure& object)
{
}

FigurePtr Canvas::CreateObject(const Figure::Type type, const Color color, const Point point, Point point2)
{
	CirclePtr circleBase; 
	SquarePtr squareBase;
	TrianglePtr triangleBase;
	LinePtr lineBase;

	FigurePtr instance;


	switch (type)
	{
	case Figure::Type::Circle:
		
		circleBase = std::make_shared<Circle>(Figure::Type::Circle);
		instance = std::static_pointer_cast<Figure>(circleBase);
		
		break;

	case Figure::Type::Square:

		squareBase = std::make_shared<Square>(Figure::Type::Square);
		instance = std::static_pointer_cast<Figure>(squareBase);

		break;

	case Figure::Type::Triangle:

		triangleBase = std::make_shared<Triangle>(Figure::Type::Triangle);
		instance = std::static_pointer_cast<Figure>(triangleBase);

		break;

	case Figure::Type::Line:

		lineBase = std::make_shared<Line>(Figure::Type::Line);
		lineBase->SetPosition2(point2);

		instance = std::static_pointer_cast<Figure>(lineBase);

		break;

	default:
		break;
	}

	instance->SetPosition(point);
	instance->SetColor(color);

	this->AddObject(instance);
	return instance;
}

void Canvas::UpdateCanvas(System::Drawing::Graphics^ graphics)
{
	graphics->Clear(System::Drawing::Color::White);

	for (const auto& object : _objects)
	{
		object->Draw(graphics);
	}

	Sleep(50);

}

std::shared_ptr<Figure> Canvas::GetObjectPointer(Point point)
{
	std::shared_ptr<Figure> pointer = nullptr;

	for (const auto& object : _objects) {

		if (object->GetType() == Figure::Type::Line) continue;

		Point position = object->GetPosition();

		double distance = sqrt((position.X - point.X) * (position.X - point.X) +
			(position.Y - point.Y) * (position.Y - point.Y));

		if (distance <= len) {
			pointer = object;
			break;
		}
	}

	return pointer;
}

Point Canvas::TakeClosestCenter(Point point)
{
	/// double min_dist = std::numeric_limits<double>::max();
	double min_dist = 1e9;

	Point point_result = point;

	for (const auto& object : _objects) {

		if (object->GetType() == Figure::Type::Line) continue;

		Point position = object->GetPosition();

		double distance = sqrt((position.X - point.X) * (position.X - point.X) +
							  (position.Y - point.Y) * (position.Y - point.Y));

		if (distance < min_dist) {
			min_dist = distance;
			point_result = position;
		}
	}

	point_result.X += len / 2;
	point_result.Y += len / 2;

	return point_result;
}

void Canvas::SaveDataInFile(std::string _filename)
{
	Logger logger(_filename);

	for (const auto& object : _objects) {

		if (object->GetType() == Figure::Type::Line) continue;
		logger.Log(object->GetType(), object->GetPosition());
	}

	for (const auto& object : _objects) {

		if (object->GetType() != Figure::Type::Line) continue;

		LinePtr line = std::static_pointer_cast<Line>(object);
		logger.Log(line->GetType(), line->GetPosition(), line->GetPosition2());
	}

}
