#pragma once

#include "FuzzySet.h"
#include "FuzzyTerm.h"
#include "FzSet.h"
#include <math.h>

// fuzzy hedges, allow us to manipulate the requirements for the DOM of an FLV


// very tightens the requirement
class FzVery : public FuzzyTerm
{
private:
	FuzzySet &set;

	FzVery(const FzVery& inst) :set(inst.set) {};
	FzVery& operator=(const FzVery&) {};

public:
	FzVery(FzSet &ft) :set(ft.set) {};

	// square the DOM value
	double GetDOM() const { return set.GetDOM() * set.GetDOM(); }

	FuzzyTerm *Clone()const { return new FzVery(*this); }
	void ClearDOM() {set.ClearDOM(); }
	void ORwithDOM(double val) { set.ORwithDOM(val); }
};

// fairly relaxes it.
class FzFairly : public FuzzyTerm
{
private:
	FuzzySet &set;

	FzFairly(const FzFairly& inst) :set(inst.set) {};
	FzFairly& operator=(const FzFairly&) {};

public:
	FzFairly(FzSet &ft) :set(ft.set) {};

	// return the sqrt of the DOM value
	double GetDOM() const { return sqrt(set.GetDOM()); }

	FuzzyTerm *Clone()const { return new FzFairly(*this); }
	void ClearDOM() { set.ClearDOM(); }
	void ORwithDOM(double val) { set.ORwithDOM(val); }
};
};