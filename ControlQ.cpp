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

*/ 



#include "pch.h"
#include "Algo.h"
#include "AlgoPdegK.h"

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
    }
    DestructAlgos();
}

