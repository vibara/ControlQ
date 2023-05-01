#pragma once
#include "Algo.h"

class AlgoPdegK : public Algo
{
public:
    AlgoPdegK();
    bool InputData(istream& in, ostream& out) override;
    void ProcessData(ostream& out) override;

private:
    int P = 0;
    int K = 0;
    int Power(int base, int exponent);
};

