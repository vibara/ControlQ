// Answers to questions here: https://www.toptal.com/algorithms/interview-questions 
// in the form of implementation

// ControlQ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Complexity:
Time complexity of counting sort is O(n+k) where n is the size of array, 
and k is the maximum element in the array, not the number of distinct elements.

1) How would you optimally calculate p^k, 
where k is a non-negative integer? What is the complexity of the solution?
And default complexity for that is O(k) 
For an even value of k, choosing a = 2 and b = k/2, 
thus having p^k = (p^2)^(k/2), 
will reduce the number of required multiplications almost in half. 
For an odd value of k, choosing x = 1 and y=k-1 will result in y being even, 
and we can then simply repeat the same process as for the even case.

2) 
Insertion sort takes elements of the array sequentially, and maintains a sorted subarray 
to the left of the current point. It does this by taking an element, finding its correct 
position in the sorted array, and shifting all following elements by 1, leaving a space 
for the element to be inserted.

Insertion sort has an average and worst runtime of O(n^2), and a best runtime of O(n). 
It doesn’t need any extra buffer, so space complexity is O(1). 
It is efficient at sorting extremely short arrays due to a very low constant factor in its complexity. 
It is also extremely good at sorting arrays that are already “almost” sorted. 
A common use is for re-sorting arrays that have had some small updates to their elements.

3)
Heapsort starts by building a max heap. 
A binary max heap is a nearly complete binary tree in which each parent node is larger or equal to its children. 
The heap is stored in the same memory in which the original array elements are. Once the heap is formed, 
it completely replaces the array. 
After that, we take and remove the first element, restore the heap property, thus reducing the heap size by 1, 
after which we place the max element at the end of that memory. 
This is repeated until we empty out the heap, resulting in the smallest element being in the first place, 
and the following elements being sequentially larger.

Heapsort has reliable time complexity and doesn’t require any extra buffer space. 
As a result, it is useful in software that requires reliable speed over optimal average runtime, 
and/or has limited memory to operate with the data. 
Thus, systems with real time requirements and memory constraints benefit the most from this algorithm.

https://web.archive.org/web/20090315200203/http://iproc.ru/parallel-programming/lection-5/

Default examples:


    I:  1 3 5 2 4 6 7 2 3 8 -> 8 7 6 3 4 3 5 1 2 2 
    II: 8 7 6 3 4 3 5 1 2 2 -> 1 2 2 3 3 4 5 6 7 8

4) 
Quicksort is performed by taking the first (leftmost) element of the array as a pivot point. 
We then compare it to each following element. When we find one that is smaller, we move it to the left. 
The moving is performed quickly by swapping that element with the first element after the pivot point, 
and then swapping the pivot point with the element after it. 
After going through the whole array, we take all points on the left of the pivot and call quicksort on that subarray, 
and we do the same to all points on the right of the pivot. The recursion is performed until we reach subarrays of 0-1 elements in length.

Quicksort is sensitive to the data provided. Without usage of random pivots, it uses O(n^2) time for sorting a full sorted array. 
But by swapping random unsorted elements with the first element, and sorting afterwards, 
the algorithm becomes less sensitive to data would otherwise cause worst-case behavior (e.g. already sorted arrays). 
Even though it doesn’t have lower complexity than Heapsort or Merge sort, 
it has a very low constant factor to its execution speed, 
which generally gives it a speed advantage when working with lots of random data.

https://medium.com/@dimko1/%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B-%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B8-quicksort-564754482e38

*/ 

#include "pch.h"
#include "Algo.h"
#include "AlgoPdegK.h"
#include "AlgoSortInsertion.h"
#include "AlgoSortHeap.h"
#include "AlgoSortQuick.h"

using namespace std;

map<int, Algo*> Algos;

void PrintStartInfo()
{
    cout << "Hello, Master. We have several algorithms." << endl;
    
    map<int, Algo*>::iterator it;
    for (it = Algos.begin(); it != Algos.end(); it++) {
        cout << it->first << ". " << it->second->ForWhat << endl;
    }

    cout << "Please select a number of algorithm: ";
}

void ConstructAlgos()
{
    Algos[1] = new AlgoPdegK();
    Algos[2] = new AlgoSortInsertion();
    Algos[3] = new AlgoSortHeap();
    Algos[4] = new AlgoSortQuick();

}

void DestructAlgos()
{
    map<int, Algo*>::iterator it;
    for (it = Algos.begin(); it != Algos.end(); it++) {
        delete it->second;
    }
}

Algo* SelectAlgo(string algoNum)
{
    try {
        int algoId = stoi(algoNum); // potential exception, see below
        auto it = Algos.find(algoId);
        if (it != Algos.end()) {
            return it->second;
        }
        else {
            cout << "Algo Id is out of range: " << algoId << endl;
        }
    }
    catch (invalid_argument const& ex) {
        cout << "Invalid value: " << ex.what() << endl;
    }
    catch (out_of_range const& ex) {
        cout << "Out of range: " << ex.what() << endl;
    }
    return nullptr;
}

int main()
{
    ConstructAlgos();
    PrintStartInfo();
    string algoNum;
    cin >> algoNum;
    auto algoPtr = SelectAlgo(algoNum);
    if (algoPtr) {
        if (algoPtr->InputData(cin, cout)) {
            algoPtr->ProcessData(cout);
        }
        else {
            cout << "Error in input data" << endl;
        }
    }
    DestructAlgos();
}

