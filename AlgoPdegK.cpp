#include "pch.h"
#include "AlgoPdegK.h"

AlgoPdegK::AlgoPdegK() : Algo() {
    ForWhat = "Calculate p^k with counting compexity";
}

bool AlgoPdegK::InputData(istream& in, ostream& out)
{
    
    try
    {
        out << "p^k, p = ";
        in >> P;
        out << "k = ";
        in >> K;
        if (P <= 0 || K <= 0) {
            throw;
        }
        return true;
    }
    catch (...)
    { 
        out << "Invalid value p or k, must be int and positive" << endl;
        return false;
    }
}

void AlgoPdegK::ProcessData(ostream& out)
{
    out << "RESULT: p^k = " << Power(P, K) << endl;
}

int AlgoPdegK::Power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    else if (exponent % 2 == 0)
    {
        return Power(base * base, exponent / 2);
    }
    else
    {
        return base * Power(base * base, (exponent - 1) / 2);
    }
}
