#pragma once
#include "pch.h"
#include "Algo.h"

class AlgoSort : public Algo
{
public:
	AlgoSort();
	bool InputData(istream& in, ostream& out) override;

protected:
	std::vector<int> CurrentArray;

	bool ParseInputStringAsArray(const string& arrayString);
	int StringToInt(const string& s);
	void PrintArray(ostream& out);

};

