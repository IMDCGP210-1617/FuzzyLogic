#include "../Utils.h"

#include "FuzzyVariable.h"
#include "FuzzySet.h"
#include "FuzzySet_Triangle.h"
#include "FuzzySet_LeftShoulder.h"
#include "FuzzySet_RightShoulder.h"
#include "FuzzySet_Singleton.h"
#include "FzSet.h"

#include <algorithm>

FuzzyVariable::~FuzzyVariable()
{
	MemberSets::iterator it;
	for (it = memberSets.begin(); it != memberSets.end(); ++it)
	{
		delete it->second;
	}
}

void FuzzyVariable::Fuzzyify(double val)
{
	MemberSets::const_iterator curSet;
	for (curSet = memberSets.begin(); curSet != memberSets.end(); ++curSet)
	{
		curSet->second->SetDOM(curSet->second->CalculateDOM(val));
	}
}

// we're just implementing max av, so we don't offer up any options here.
double FuzzyVariable::Defuzzify() const
{
	double bottom = 0.0;
	double top = 0.0;

	MemberSets::const_iterator curSet;
	for (curSet = memberSets.begin(); curSet != memberSets.end(); ++curSet)
	{
		bottom += curSet->second->GetDOM();
		top += curSet->second->GetRepresentativeValue() * curSet->second->GetDOM();
	}

	if (isEqual(0, bottom)) return 0.0;

	return top / bottom;
}

FzSet FuzzyVariable::AddTriangularSet(std::string name,
	double       minBound,
	double       peak,
	double       maxBound)
{
	memberSets[name] = new FuzzySet_Triangle(peak,
		peak - minBound,
		maxBound - peak);
	//adjust range if necessary
	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*memberSets[name]);
}

FzSet FuzzyVariable::AddLeftShoulderSet(std::string name,
	double       minBound,
	double       peak,
	double       maxBound)
{
	memberSets[name] = new FuzzySet_LeftShoulder(peak, peak - minBound, maxBound - peak);

	//adjust range if necessary
	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*memberSets[name]);
}

FzSet FuzzyVariable::AddRightShoulderSet(std::string name,
	double       minBound,
	double       peak,
	double       maxBound)
{
	memberSets[name] = new FuzzySet_RightShoulder(peak, peak - minBound, maxBound - peak);

	//adjust range if necessary
	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*memberSets[name]);
}

FzSet FuzzyVariable::AddSingletonSet(std::string name,
	double       minBound,
	double       peak,
	double       maxBound)
{
	memberSets[name] = new FuzzySet_Singleton(peak,
		peak - minBound,
		maxBound - peak);

	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*memberSets[name]);
}

void FuzzyVariable::AdjustRangeToFit(double minBound, double maxBound)
{
	if (minBound < minRange) minRange = minBound;
	if (maxBound > maxRange) maxRange = maxBound;
}