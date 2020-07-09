#include "Canvas.h"

#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Line.h"

#include "windows.h"

#include <fstream>;
#include <regex>

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
		
		lineBase->SetPosition(point);
		lineBase->SetPosition2(point2);

		instance = std::static_pointer_cast<Figure>(lineBase);

		this->AddObject(instance);

		/// cant work without adding object 
		this->GetObjectPointer(lineBase->GetPosition())->AddLine(lineBase);
		this->GetObjectPointer(lineBase->GetPosition2())->AddLine(lineBase);

		break;

	default:
		break;
	}

	instance->SetPosition(point);
	instance->SetColor(color);

	// beacuse line 79 in this code
	if (type != Figure::Type::Line) this->AddObject(instance);
	return instance;
}

void Canvas::UpdateCanvas(System::Drawing::Graphics^ graphics)
{
	for (const auto& object : _objects)
	{
		object->Draw(graphics, Color::Black);
	}

	Sleep(50);
}

void Canvas::ClearRenderLines(System::Drawing::Graphics^ graphics)
{
	for (const auto& object : _objects) if (object->GetType() == Figure::Type::Line)
	{
		object->Draw(graphics, Color::White);
	}
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

void Canvas::LoadDataFromFile(std::string _filename)
{

	auto ObjectsCopy = _objects;

	try {


		// _objects.clear();
		_objects.clear();

		std::ifstream in(_filename);
		std::string str_in;

		// Regexp for reading data from file
		std::cmatch result;
		std::regex regular("[0-9]+");

		// Read all data from file by line
		while (std::getline(in, str_in)) {

			std::vector<int> input_data;

			// Search all numbers in line
			while (regex_search(str_in.c_str(), result, regular)) {

				int intValue = std::stoi(result[0]);
				input_data.push_back(intValue);

				str_in = result.suffix().str();
			}

			if (input_data.size() != 3 && input_data.size() != 5) {
				throw std::runtime_error("Invalid file");
			}


			Point position1;
			Point position2;

			// Create new objects
			switch ((Figure::Type)input_data[0])
			{

			case Figure::Type::Circle:
			case Figure::Type::Triangle:
			case Figure::Type::Square:

				position1 = Point(input_data[1], input_data[2]);
				this->CreateObject((Figure::Type)input_data[0], Color::Black, position1);

				break;

			case Figure::Type::Line:

				position1 = Point(input_data[1], input_data[2]);
				position2 = Point(input_data[3], input_data[4]);
				this->CreateObject((Figure::Type)input_data[0], Color::Black, position1, position2);


				break;
			}
		}

		in.close();
	}
	catch (...) {

		/// assert
		_objects = ObjectsCopy;
	}
}

void Canvas::ClearCanvas()
{
	_objects.clear();
}
