#pragma once
#include "AlgoSort.h"

class AlgoSortInsertion : public AlgoSort
{
public:
	AlgoSortInsertion();
	virtual void ProcessData(ostream& out);

private:
	void InsertToSortedPart(int sortedSize, int newElement);
	void Shift(int fromPosition, int sortedSize);
};

