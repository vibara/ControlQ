#include "AlgoSort.h"

using namespace std;

AlgoSort::AlgoSort() : Algo()
{
}

bool AlgoSort::InputData(istream& in, ostream& out)
{
	out << "Array as 2 4 1 ... n: ";
	string arrayString;
	getline(in, arrayString);
	return ParseInputStringAsArray(arrayString);
}

bool AlgoSort::ParseInputStringAsArray(const string& arrayString)
{
	string currentVal{};
	for (int i = 0; i < arrayString.length(); i++)	// TODO: check how to replace seach for the string
	{
		if (arrayString[i] >= '0' && arrayString[i] <= 9)
		{
			currentVal += arrayString[i];  // how long can be the number? what if it is too long?
		}
		else if (arrayString[i] == ' ')
		{
			CurrentArray.push_back(StringToInt(currentVal));
			currentVal = "";
		}
		else if (arrayString[i] == '\n')
		{
			break;
		}
		else
		{
			return false;
		}
	}
	if (currentVal.length() > 0)
	{
		CurrentArray.push_back(StringToInt(currentVal));
	}
}

int AlgoSort::StringToInt(const string& s)
{
	return stoi(s);
}

void AlgoSort::PrintArray(ostream& out)
{
	for (auto& elem : CurrentArray)
	{
		out << elem << " ";
	}
	out << endl;
}