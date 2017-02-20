#pragma once

#include <math.h>
#include <limits>

const int     MaxInt = (std::numeric_limits<int>::max)();
const double  MaxDouble = (std::numeric_limits<double>::max)();
const double  MinDouble = (std::numeric_limits<double>::min)();
const float   MaxFloat = (std::numeric_limits<float>::max)();
const float   MinFloat = (std::numeric_limits<float>::min)();

const double   Pi = 3.14159;
const double   TwoPi = Pi * 2;
const double   HalfPi = Pi / 2;
const double   QuarterPi = Pi / 4;

inline bool isEqual(float a, float b)
{
	if (fabs(a - b) < 1E-12)
	{
		return true;
	}

	return false;
}

inline bool isEqual(double a, double b)
{
	if (fabs(a - b) < 1E-12)
	{
		return true;
	}

	return false;
}