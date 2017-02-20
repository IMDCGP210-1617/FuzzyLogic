#pragma once
#include "FuzzySet.h"
#include "../Utils.h"

class FuzzySet_LeftShoulder : public FuzzySet
{
private:
	double peakPoint;
	double leftOffset;
	double rightOffset;

public:
	FuzzySet_LeftShoulder(double peak, double left, double right) : FuzzySet(((peak - left) + peak) / 2), peakPoint(peak), leftOffset(left), rightOffset(right) {};

	double CalculateDOM(double val) const;
};

