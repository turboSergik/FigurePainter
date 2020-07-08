#pragma once

#include "vector"
#include "memory"

class Figure;
class Circle;
class Line;
class Square;
class Triangle;


using FigurePtr = std::shared_ptr<Figure>;
using CirclePtr = std::shared_ptr<Circle>;
using SquarePtr = std::shared_ptr<Square>;
using TrianglePtr = std::shared_ptr<Triangle>;
using LinePtr = std::shared_ptr<Line>;

using ObjectVector = std::vector<FigurePtr>;

using Point = System::Drawing::Point;
using Color = System::Drawing::Color;


const int len = 50; /// Deffault len for all figures
