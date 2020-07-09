#pragma once

#include <string>

#include "Figure.h"
#include "Logger.h"

class Canvas
{
public:

	static Canvas* GetInstance();

	void AddObject(const std::shared_ptr<Figure> object);
	void RemoveObject(const Figure& object);

	FigurePtr CreateObject(const Figure::Type type, const Color color, const Point point, Point point2 = Point(0, 0));

	void UpdateCanvas(System::Drawing::Graphics^ graphics);
	std::shared_ptr<Figure> GetObjectPointer(Point point);

	Point TakeClosestCenter(Point point);

	void SaveDataInFile(std::string _filename);

private:

	Canvas();
	static Canvas* _instance;

	Canvas(const Canvas&) = delete;
	Canvas& operator=(const Canvas) = delete;

	ObjectVector _objects;
};
