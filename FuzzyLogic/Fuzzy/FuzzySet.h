#pragma once

// Fuzzy Set is the base class we use to represent any given fuzzy set manifold (in this case, we have implemented shoulders, triangle and singleton shapes).
class FuzzySet
{
protected:
	double DOM;
	double RepresentativeValue;

public:
	FuzzySet(double repVal) : RepresentativeValue(repVal), DOM(0.0) {};
	virtual double CalculateDOM(double val) const = 0;
	void ORwithDOM(double val) { if (val > DOM) DOM = val; };

	double GetRepresentativeValue() const { return RepresentativeValue; }
	void ClearDOM() { DOM = 0.0; }
	double GetDOM() const { return DOM; }
	void SetDOM(double val) { DOM = val; }
};

