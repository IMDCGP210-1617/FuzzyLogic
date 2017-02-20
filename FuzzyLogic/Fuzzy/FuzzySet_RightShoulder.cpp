#include "FuzzySet_RightShoulder.h"

double FuzzySet_RightShoulder::CalculateDOM(double val) const
{
	if ((isEqual(rightOffset, 0.0) && isEqual(peakPoint, val)) || (isEqual(leftOffset, 0.0) && isEqual(peakPoint, val)))
	{
		return 1.0;
	}
	else if ((val <= peakPoint) && (val > (peakPoint - leftOffset)))
	{
		double grad = 1.0 / leftOffset;
		return grad * (val - (peakPoint - leftOffset));
	} 
	else if ((val > peakPoint) && (val <= (peakPoint + rightOffset)))
	{
		return 1.0;
	}
	else
	{
		return 0.0;
	}
}
