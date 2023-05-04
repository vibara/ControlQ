#include "pch.h"
#include "AlgoSortQuick.h"

AlgoSortQuick::AlgoSortQuick() : AlgoSort()
{
	ForWhat = "Sorting: Quick Sort method";
}

void AlgoSortQuick::ProcessData(ostream& out)
{
	
	SplitAndSort(0, CurrentArray.size()-1, out);
}

void AlgoSortQuick::SplitAndSort(int from, int to, ostream& out)
{
	if (to - from > 0)
	{
		
		out << "Split from pos " << from << " to pos " << to << endl;
		int pivot = from;
		// small goes left
		bool res = true;
		do 
		{
		} while (FindAndSwapLess(pivot, to));

		do
		{
		} while (FindAndSwapMore(from, pivot));

		PrintArray(out);
		out << "Pivot pos: " << pivot << endl;

		SplitAndSort(from, pivot - 1, out);
		SplitAndSort(pivot + 1, to, out);
	}

		
}

bool AlgoSortQuick::FindAndSwapLess(int& pivot, int to)
{
	for (int i = pivot + 1; i <= to; i++)
	{
		if (CurrentArray[i] < CurrentArray[pivot])
		{
			if (i != pivot + 1)
			{
				// remember pivot:
				int pivotVal = CurrentArray[pivot];
				// less value move to pivot:
				CurrentArray[pivot] = CurrentArray[i];
				// remember val right of pivot:
				int rightVal = CurrentArray[pivot + 1];
				// put pivot there:
				CurrentArray[pivot + 1] = pivotVal;
				// put right val there val less val:
				CurrentArray[i] = rightVal;
			}
			else
			{
				std::swap(CurrentArray[pivot], CurrentArray[i]);
			}
			// increase pivot:
			pivot ++;
			return true;
		}
	}
	return false;
}


bool AlgoSortQuick::FindAndSwapMore(int from, int& pivot)
{
	for (int i = from; i < pivot; i++)
	{
		if (CurrentArray[i] > CurrentArray[pivot])
		{
			if (i != pivot - 1) 
			{
				// remember pivot:
				int pivotVal = CurrentArray[pivot];
				// more value move to pivot:
				CurrentArray[pivot] = CurrentArray[i];
				// remember val left of pivot:
				int leftVal = CurrentArray[pivot - 1];
				// put pivot there:
				CurrentArray[pivot - 1] = pivotVal;
				// put left val there val less val:
				CurrentArray[i] = leftVal;
				// decrease pivot:
			}
			else
			{
				std::swap(CurrentArray[pivot], CurrentArray[i]);
			}
			pivot--;
			return true;
		}
	}
	return false;
}



