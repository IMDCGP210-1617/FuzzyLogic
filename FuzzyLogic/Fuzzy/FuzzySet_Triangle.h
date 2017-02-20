#pragma once

#include "FuzzySet.h"
#include "../Utils.h"

class FuzzySet_Triangle : public FuzzySet
{
private:
	double peakPoint;
	double leftOffset;
	double rightOffset;

public:
	FuzzySet_Triangle(double mid, double left, double right) :FuzzySet(mid), peakPoint(mid), leftOffset(left), rightOffset(right) {};
	
	double CalculateDOM(double val) const;
};

