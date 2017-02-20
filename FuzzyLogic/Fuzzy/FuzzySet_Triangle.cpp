#include "FuzzySet_Triangle.h"

double FuzzySet_Triangle::CalculateDOM(double val) const
{
	if ((isEqual(rightOffset, 0.0) && isEqual(peakPoint, 0.0)) || (isEqual(leftOffset, 0.0) && isEqual(peakPoint, 0.0)))
	{
		return 1.0;
	}

	// left of center
	if ((val <= peakPoint) && (val >= (peakPoint - leftOffset)))
	{
		double grad = 1.0 / leftOffset;

		return grad * (val - (peakPoint - leftOffset));
	}
	// right of center
	else if ((val > peakPoint) && (val < (peakPoint + rightOffset)))
	{
		double grad = 1.0 / -rightOffset;

		return grad * (val - peakPoint) + 1.0;
	}
	// out of range of this FLV, return zero
	else
	{
		return 0.0;
	}
}
