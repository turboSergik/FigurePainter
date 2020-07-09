#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "Forward.hpp"
#include "Figure.h"


class Logger
{

public:

	explicit Logger(const std::string filename);
	virtual ~Logger();

	void Log(const Figure::Type type);
	void Log(const Figure::Type type, Point point);
	void Log(const Figure::Type type, Point point1, Point point2);

private:

	Logger() = delete;

	std::ofstream fout;
	const std::string _filename;
};