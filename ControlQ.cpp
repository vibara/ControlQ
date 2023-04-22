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
*/ 



#include "pch.h"
#include "Algo.h"
#include "AlgoPdegK.h"
#include "AlgoSortInsertion.h"

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

