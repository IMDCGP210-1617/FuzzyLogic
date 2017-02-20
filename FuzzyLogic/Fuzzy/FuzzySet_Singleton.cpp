#include "FuzzySet_Singleton.h"

double FuzzySet_Singleton::CalculateDOM(double val) const
{
	if ((val >= midPoint - leftOffset) && (val <= midPoint + rightOffset))
	{
		return 1.0;
	}
	else {
		return 0.0;
	}
}
