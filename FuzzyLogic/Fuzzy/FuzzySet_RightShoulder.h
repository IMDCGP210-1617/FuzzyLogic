#pragma once
#include "FuzzySet.h"
#include "../Utils.h"

class FuzzySet_RightShoulder : public FuzzySet
{
private:
	double peakPoint;
	double leftOffset;
	double rightOffset;

public:
	FuzzySet_RightShoulder(double peak, double left, double right) :FuzzySet(((peak + right) + peak) / 2), peakPoint(peak), leftOffset(left), rightOffset(right) {};

	double CalculateDOM(double val) const;
};

