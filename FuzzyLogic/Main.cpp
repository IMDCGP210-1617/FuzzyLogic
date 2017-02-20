#include <windows.h>
#include <iostream>

#include "fuzzy\FuzzyModule.h"
#include "fuzzy\FzSet.h"

int main(int argc, char *argv[])
{
	FuzzyModule fm;

	FuzzyVariable &DistToTarget = fm.CreateFLV("DistToTarget");

	FzSet TargetClose = DistToTarget.AddLeftShoulderSet("Target Close", 0, 25, 150);
	FzSet TargetMedium = DistToTarget.AddTriangularSet("Target Medium", 25, 50, 300);
	FzSet TargetFar = DistToTarget.AddRightShoulderSet("Target Far", 150, 300, 500);


	FuzzyVariable &AmmoStatus = fm.CreateFLV("AmmoStatus");

	FzSet AmmoLow = AmmoStatus.AddLeftShoulderSet("Ammo Low", 0, 0, 10);
	FzSet AmmoOKay = AmmoStatus.AddTriangularSet("Ammo Okay", 0, 10, 30);
	FzSet AmmoLoads = AmmoStatus.AddRightShoulderSet("Ammo Loads", 10, 30, 40);

	FuzzyVariable &Desirability = fm.CreateFLV("Desirability");

	FzSet Undesirable = Desirability.AddLeftShoulderSet("Undesirable", 0, 25, 50);
	FzSet Desirable = Desirability.AddTriangularSet("Desirable", 25, 50, 75);
	FzSet VeryDesirable = Desirability.AddRightShoulderSet("Very Desirable", 50, 75, 100);

	fm.AddRule(FzAND(TargetClose, AmmoLoads), Undesirable);
	fm.AddRule(FzAND(TargetClose, AmmoOKay), Undesirable);
	fm.AddRule(FzAND(TargetClose, AmmoLow), Undesirable);

	fm.AddRule(FzAND(TargetMedium, AmmoLoads), VeryDesirable);
	fm.AddRule(FzAND(TargetMedium, AmmoOKay), VeryDesirable);
	fm.AddRule(FzAND(TargetMedium, AmmoLow), Desirable);

	fm.AddRule(FzAND(TargetFar, AmmoLoads), Desirable);
	fm.AddRule(FzAND(TargetFar, AmmoOKay), Desirable);
	fm.AddRule(FzAND(TargetFar, AmmoLow), Undesirable);

	//Combs method:

	/*fm.AddRule(TargetClose, Undesirable);
	fm.AddRule(TargetMedium, VeryDesirable);
	fm.AddRule(TargetFar, Undesirable);

	fm.AddRule(AmmoLow, Undesirable);
	fm.AddRule(AmmoOKay, Desirable);
	fm.AddRule(AmmoLoads, VeryDesirable);*/

	fm.Fuzzify("AmmoStatus", 8);
	fm.Fuzzify("DistToTarget", 200);

	double result = fm.Defuzzify("Desirability");

	std::cout << "Crisp value of Desirability: " << result << std::endl;

	std::getchar();
	return 0;
}