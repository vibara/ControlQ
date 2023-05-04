#pragma once
#include "AlgoSort.h"
class AlgoSortQuick : public AlgoSort
{

public:
	AlgoSortQuick();
	void ProcessData(ostream& out) override;

private:
	void SplitAndSort(int from, int to, ostream& out);
	bool FindAndSwapLess(int& split, int to);
	bool FindAndSwapMore(int from, int& split);

};

