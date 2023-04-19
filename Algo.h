#pragma once

using namespace std;

class Algo
{
public:
	string ForWhat;

	virtual bool InputData(istream& in, ostream& out) = 0;
	virtual void ProcessData(ostream& out) = 0;
};

