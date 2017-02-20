#include "FuzzyOperators.h"

FzAND::FzAND(const FzAND& fa)
{
	// we clone the terms being passed in to the constructor
	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = fa.terms.begin(); curTerm != fa.terms.end(); ++curTerm)
	{
		terms.push_back((*curTerm)->Clone());
	}
}

FzAND::FzAND(FuzzyTerm& op1, FuzzyTerm& op2)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
}

FzAND::FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
	terms.push_back(op3.Clone());
}

FzAND::FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
	terms.push_back(op3.Clone());
	terms.push_back(op4.Clone());
}

FzAND::~FzAND()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		delete *curTerm;
	}
}

// AND finds the minimum DOM from all associated terms.
double FzAND::GetDOM()const
{
	double smallest = MaxDouble;

	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		if ((*curTerm)->GetDOM() < smallest)
		{
			smallest = (*curTerm)->GetDOM();
		}
	}

	return smallest;
}

void FzAND::ORwithDOM(double val)
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		(*curTerm)->ORwithDOM(val);
	}
}

void FzAND::ClearDOM()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		(*curTerm)->ClearDOM();
	}
}

FzOR::FzOR(const FzOR& fa)
{
	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = fa.terms.begin(); curTerm != fa.terms.end(); ++curTerm)
	{
		terms.push_back((*curTerm)->Clone());
	}
}

FzOR::FzOR(FuzzyTerm& op1, FuzzyTerm& op2)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
}

FzOR::FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
	terms.push_back(op3.Clone());
}

FzOR::FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
{
	terms.push_back(op1.Clone());
	terms.push_back(op2.Clone());
	terms.push_back(op3.Clone());
	terms.push_back(op4.Clone());
}


FzOR::~FzOR()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		delete *curTerm;
	}
}

// OR finds the highest DOM of all the associated terms.
double FzOR::GetDOM()const
{
	double largest = MinFloat;

	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = terms.begin(); curTerm != terms.end(); ++curTerm)
	{
		if ((*curTerm)->GetDOM() > largest)
		{
			largest = (*curTerm)->GetDOM();
		}
	}

	return largest;
}