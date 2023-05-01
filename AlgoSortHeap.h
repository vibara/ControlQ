#pragma once
#include "AlgoSort.h"
class AlgoSortHeap : public AlgoSort
{
public:
	AlgoSortHeap();
	virtual void ProcessData(ostream& out);

private:
	int SwapsNumber = 0;

	inline int LeftChildIndex(int parentIndex) { return parentIndex * 2 + 1;  }
	inline int RightChildIndex(int parentIndex) { return parentIndex * 2 + 2; }
	inline int ParentIndex(int childIndex) { return (childIndex % 2) == 0 ? (childIndex - 2) / 2 : 	(childIndex - 1) / 2;  }

	void SiftingUp(int index);
	void HighestToTail(int lastIndex, ostream& out);
	void SiftingDown(int index, int arraySize);


};

