#pragma once

#include <vector>
#include "FuzzySet.h"
#include "FuzzyOperators.h"
#include "../Utils.h"

// A Fuzzy Rule puts together a fuzzy set as antecedent and a fuzzy set as consequence.
// the Fuzzy sets can be the result of the AND or OR operators.
class FuzzyRule
{
private:
	const FuzzyTerm *antecedent;
	FuzzyTerm* consequence;

	FuzzyRule(const FuzzyRule&);
	FuzzyRule& operator=(const FuzzyRule&) {};

public:
	FuzzyRule(const FuzzyTerm& ant, const FuzzyTerm& con) :antecedent(ant.Clone()), consequence(con.Clone()) {};
	~FuzzyRule() { delete antecedent; delete consequence; }

	void SetConfidenceofConsequentToZero() { consequence->ClearDOM(); }

	void Calculate()
	{
		consequence->ORwithDOM(antecedent->GetDOM());
	}
};

