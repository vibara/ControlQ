#pragma once
#include "AlgoSort.h"

class AlgoSortInsertion : public AlgoSort
{
public:
	AlgoSortInsertion();
	void ProcessData(ostream& out) override;

private:
	void InsertToSortedPart(int sortedSize, int newElement);
	void Shift(int fromPosition, int sortedSize);
};

