#include "pch.h"
#include "AlgoSortHeap.h"

AlgoSortHeap::AlgoSortHeap() : AlgoSort() 
{
	ForWhat = "Sorting: Heap Sort method";
}

void AlgoSortHeap::ProcessData(ostream& out)
{
	out << "First step (sorning botton->top, partial): " << endl;

	PrintArray(out);
	for (int i = 1; i < CurrentArray.size(); i++)
	{
		SiftingUp(i);
		PrintArray(out);
	}
	out << "Swaps: " << SwapsNumber << endl;

	out << "Second step (max to the end, sort head top->bottom): " << endl;

	for (int i = CurrentArray.size() - 1; i > 0; i--)
	{
		HighestToTail(i, out);
		out << "Swaps: " << SwapsNumber << endl;
	}

}


void AlgoSortHeap::SiftingUp(int index)
{
	if (index >= 0) 
	{	// index can be less than zero if we called NewItemToHeap from the parent function
		int parentIndex = ParentIndex(index);
		if (parentIndex >= 0 && CurrentArray[parentIndex] < CurrentArray[index])
		{
			std::swap(CurrentArray[parentIndex], CurrentArray[index]);
			SwapsNumber++;
			SiftingUp(parentIndex);
		}
	}
}


void AlgoSortHeap::HighestToTail(int lastIndex, ostream& out)
{
	// swap last and head
	std::swap(CurrentArray[0], CurrentArray[lastIndex]);
	SwapsNumber++;
	PrintArray(out);

	SiftingDown(0, lastIndex);
	PrintArray(out);
}


void AlgoSortHeap::SiftingDown(int index, int arraySize)
{
	if (arraySize > 0)
	{
		auto leftChildIndex = LeftChildIndex(index);
		auto rightChildIndex = RightChildIndex(index);
		int indexOfMax = index;
		if (leftChildIndex < arraySize && CurrentArray[leftChildIndex] > CurrentArray[indexOfMax]) {
			indexOfMax = leftChildIndex;
		}
		if (rightChildIndex < arraySize && CurrentArray[rightChildIndex] > CurrentArray[indexOfMax]) {
			indexOfMax = rightChildIndex;
		}
		if (indexOfMax != index)
		{
			std::swap(CurrentArray[index], CurrentArray[indexOfMax]);
			SiftingDown(indexOfMax, arraySize);
		}
	}
}

