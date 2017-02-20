#include "FuzzySet_LeftShoulder.h"

double FuzzySet_LeftShoulder::CalculateDOM(double val) const
{
	if ((isEqual(rightOffset, 0.0) && isEqual(peakPoint, val)) || (isEqual(leftOffset, 0.0) && isEqual(peakPoint, val)))
	{
		return 1.0;
	}

	// right of center
	if ((val >= peakPoint) && (val < peakPoint + rightOffset))
	{
		double grad = 1.0 / -rightOffset;

		return grad * (val - peakPoint) + 1.0;
	} 
	// left of center
	else if ((val < peakPoint) && (val >= peakPoint - leftOffset))
	{
		return 1.0;
	}
	else
	{
		return 0.0;
	}
}
