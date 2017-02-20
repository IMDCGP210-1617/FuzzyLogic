#pragma once
#include "FuzzySet.h"
#include "../Utils.h"

class FuzzySet_Singleton :	public FuzzySet
{
private:
	double midPoint;
	double leftOffset;
	double rightOffset;

public:
	FuzzySet_Singleton(double mid, double left, double right) :FuzzySet(mid), midPoint(mid), leftOffset(left), rightOffset(right) {};

	double CalculateDOM(double val) const;
};

