#pragma once

#include <string>

#include "Figure.h"

#include "Line.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

#include "Logger.h"

class Canvas
{
public:

	static Canvas* GetInstance();

	void AddObject(const std::shared_ptr<Figure> object);
	void RemoveObject(const Figure& object);

	FigurePtr CreateObject(const Figure::Type type, const Color color, const Point point, Point point2 = Point(0, 0));

	void UpdateCanvas(System::Drawing::Graphics^ graphics);
	void ClearRenderLines(System::Drawing::Graphics^ graphics);

	std::shared_ptr<Figure> GetObjectPointer(Point point);

	Point TakeClosestCenter(Point point);

	void SaveDataInFile(std::string _filename);
	void LoadDataFromFile(std::string _filename);

	void ClearCanvas();
	ObjectVector GetCanvasObjects() const;

	bool CanDrawNewFrame = true;

private:

	Canvas();
	static Canvas* _instance;

	Canvas(const Canvas&) = delete;
	Canvas& operator=(const Canvas) = delete;

	ObjectVector _objects;
};
