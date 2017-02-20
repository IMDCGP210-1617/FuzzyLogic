#pragma once

#include <map>
#include <string>
#include <vector>

#include "FuzzyVariable.h"
#include "FuzzyRule.h"
#include "FuzzyTerm.h"

// FuzzyModule is the core of the fuzzy logic system, it contains a map of fuzzy variables
// and a vector of fuzzy rules.

// each agent / object that wants to use fuzzy logic should have a fuzzy module.
class FuzzyModule
{
private:
	typedef std::map<std::string, FuzzyVariable*> VarMap;

private:
	// map of all the fuzzy variables used by this module
	VarMap variables;

	// vector of all the fuzzy rules.
	std::vector<FuzzyRule*> rules;

	// zeros the DoMs of the consequents of each rule.
	inline void SetConfidencesofConsequentsToZero();

public:
	~FuzzyModule();

	// creates an empty fuzzy variable and returns a reference to it
	FuzzyVariable& CreateFLV(const std::string& varName);

	// adds a rule to the module
	void AddRule(FuzzyTerm &antecedent, FuzzyTerm& consequence);

	// calls the fuzzify method of the specified flv
	void Fuzzify(const std::string &NameOfFLV, double val);

	// returns the crisp value of the given flv.
	double Defuzzify(const std::string &key);
};

