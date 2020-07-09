#include "Logger.h"

Logger::Logger(const std::string filename):
	_filename(filename)
{
	fout = std::ofstream(_filename);
}

Logger::~Logger()
{
	fout.close();
}

void Logger::Log(const Figure::Type type)
{
}

void Logger::Log(const Figure::Type type, Point point)
{
	fout << (int)type << " " << point.X << " " << point.Y << "\n";
}

void Logger::Log(const Figure::Type type, Point point1, Point point2)
{
	fout << (int)type << " " << point1.X << " " << point1.Y << " " << point2.X << " " << point2.Y << "\n";
}
