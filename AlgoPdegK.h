#pragma once
#include "Algo.h"

class AlgoPdegK : public Algo
{
public:
    AlgoPdegK();
    virtual bool InputData(istream& in, ostream& out);
    virtual void ProcessData(ostream& out);

private:
    int P = 0;
    int K = 0;
    int Power(int base, int exponent);
};

