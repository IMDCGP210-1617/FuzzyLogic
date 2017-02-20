#pragma once

#include "FuzzySet.h"
#include "FuzzyTerm.h"

// FzSet is a proxy class for a fuzzy set - it inherits from fuzzy term, so we have a common interface across all the fuzzy types we can work with directly.
class FzSet : public FuzzyTerm
{
private:
	friend class FzVery;
	friend class FzFairly;

private:
	FuzzySet &set;

public:
	FzSet(FuzzySet& fs) :set(fs) {};

	FuzzyTerm *Clone()const { return new FzSet(*this); }
	double GetDOM()const { return set.GetDOM(); }
	void ClearDOM() { set.ClearDOM(); }
	void ORwithDOM(double val) { set.ORwithDOM(val); }
};

