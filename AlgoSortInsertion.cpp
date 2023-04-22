#include "pch.h"
#include "AlgoSortInsertion.h"

AlgoSortInsertion::AlgoSortInsertion() : AlgoSort() {
	ForWhat = "Sorting: Insertion method";
}

void AlgoSortInsertion::ProcessData(ostream& out)
{
	for (unsigned int iUnsorted = 0; iUnsorted + 1 < CurrentArray.size(); iUnsorted++)  
	{
		InsertToSortedPart(iUnsorted, CurrentArray[iUnsorted+1]);
		PrintArray(out);
	}
}

void AlgoSortInsertion::InsertToSortedPart(int sortedSize, int newElement)
{

	for (int i = 0; i < sortedSize; i++)
	{
		if (newElement < CurrentArray[i])
		{
			Shift(i, sortedSize);
			CurrentArray[i] = newElement;
			break;
		}
	}
}

void AlgoSortInsertion::Shift(int fromPosition, int sortedSize)
{
	for (int i = sortedSize; i > fromPosition; i--)
	{
		CurrentArray[i] = CurrentArray[i - 1];
	}
}