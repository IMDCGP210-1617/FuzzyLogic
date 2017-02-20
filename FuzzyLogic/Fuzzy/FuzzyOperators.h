#pragma once

#include <vector>
#include "..\Utils.h"
#include "FuzzyTerm.h"

// The AND operator - combines sets and returns the lowest DOM of any of them.
class FzAND : public FuzzyTerm
{
private:
	//an instance of this class may AND together up to 4 terms
	std::vector<FuzzyTerm*> terms;

	FzAND& operator= (const FzAND&) {};

public:

	~FzAND();

	FzAND(const FzAND& fa);

	FzAND(FuzzyTerm& op1, FuzzyTerm& op2);
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);

	FuzzyTerm *Clone() const { return new FzAND(*this); }

	double GetDOM() const;
	void ClearDOM();
	void ORwithDOM(double val);
};

// the OR operator, combines sets and returns the highest DOM of any of them.
class FzOR : public FuzzyTerm
{
private:

	//an instance of this class may OR together up to 4 terms
	std::vector<FuzzyTerm*> terms;

	//no assignment op necessary
	FzOR& operator=(const FzOR&);

public:

	~FzOR();

	//copy ctor
	FzOR(const FzOR& fa);

	FzOR(FuzzyTerm& op1, FuzzyTerm& op2);
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);

	//virtual ctor
	FuzzyTerm* Clone()const { return new FzOR(*this); }

	double GetDOM()const;

	//unused, but we need to implement
	void ClearDOM() {}
	void ORwithDOM(double val) { }
};