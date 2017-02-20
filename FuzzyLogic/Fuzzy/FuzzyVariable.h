#pragma once
#include <map>
#include <string>

// forward declaration of classes - there's quite a lot of cyclical including going on otherwise.
class FuzzySet;
class FzSet;
class FuzzyModule;

// Fuzzy Variables are the accumulation of a number of fuzzy sets, which form a manifold
// they maintain a map of sets and each time a set is added, the range covered by the variable is recalculated.
class FuzzyVariable
{
public:
	typedef std::map<std::string, FuzzySet*> MemberSets;

private:
	FuzzyVariable(const FuzzyVariable&);
	FuzzyVariable& operator=(const FuzzyVariable&) {};

private:

	MemberSets memberSets;

	double minRange;
	double maxRange;

	void AdjustRangeToFit(double min, double max);

	~FuzzyVariable();

	friend class FuzzyModule;

public:

	FuzzyVariable() : minRange(0.0), maxRange(0.0) {};
	FzSet AddLeftShoulderSet(std::string name, double minBound, double peak, double maxBound);
	FzSet AddRightShoulderSet(std::string name, double minBound, double peak, double maxBound);
	FzSet AddTriangularSet(std::string name, double minBound, double peak, double maxBound);
	FzSet AddSingletonSet(std::string name, double minBound, double peak, double maxBound);

	void Fuzzyify(double val);

	double Defuzzify() const;
};

