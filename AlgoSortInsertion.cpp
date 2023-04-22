#include "pch.h"
#include "AlgoSortInsertion.h"

AlgoSortInsertion::AlgoSortInsertion() : AlgoSort() {
	ForWhat = "Sorting: Insertion method";
}

void AlgoSortInsertion::ProcessData(ostream& out)
{
	for (unsigned int sortedSize = 1; sortedSize < CurrentArray.size(); sortedSize++)
	{
		InsertToSortedPart(sortedSize, CurrentArray[sortedSize]);
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