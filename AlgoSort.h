#pragma once
#include "pch.h"
#include "Algo.h"

class AlgoSort : public Algo
{
public:
	AlgoSort();
	virtual bool InputData(istream& in, ostream& out);

protected:
	std::vector<int> CurrentArray;

	bool ParseInputStringAsArray(const string& arrayString);
	int StringToInt(const string& s);
	void PrintArray(ostream& out);

};

