#include "FuzzyModule.h"


// resets every consequents of each rule attached to the module to zero.
inline void FuzzyModule::SetConfidencesofConsequentsToZero()
{
	std::vector<FuzzyRule*>::iterator curRule = rules.begin();
	for (curRule; curRule != rules.end();++curRule)
	{
		(*curRule)->SetConfidenceofConsequentToZero();
	}
}

// tidy up memory usage by deleting any associated rules or variables.
FuzzyModule::~FuzzyModule()
{
	VarMap::iterator curVar = variables.begin();
	for (curVar; curVar != variables.end(); ++curVar)
	{
		delete curVar->second;
	}

	std::vector<FuzzyRule*>::iterator curRule = rules.begin();
	for (curRule; curRule != rules.end(); ++curRule)
	{
		delete *curRule;
	}
}

FuzzyVariable & FuzzyModule::CreateFLV(const std::string & varName)
{
	// instantiate a new fuzzy variable, but don't do anything with it other than return a reference
	variables[varName] = new FuzzyVariable();

	return *variables[varName];
}

// add a new rule to the rules vector
void FuzzyModule::AddRule(FuzzyTerm & antecedent, FuzzyTerm & consequence)
{
	rules.push_back(new FuzzyRule(antecedent, consequence));
}

// find the matching variable and fuzzify the crisp value against it.
void FuzzyModule::Fuzzify(const std::string & NameOfFLV, double val)
{
	variables[NameOfFLV]->Fuzzyify(val);
}

// retrieve a crisp value from a given variable.
double FuzzyModule::Defuzzify(const std::string & key)
{
	SetConfidencesofConsequentsToZero();

	std::vector<FuzzyRule*>::iterator curRule = rules.begin();
	for (curRule; curRule != rules.end();++curRule)
	{
		(*curRule)->Calculate();
	}

	return variables[key]->Defuzzify();
}
