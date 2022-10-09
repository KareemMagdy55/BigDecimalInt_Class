#pragma once

using namespace std;

class BigDecimalInt{
    private:
        string BDI ;
    public:
        BigDecimalInt(string decStr);
        BigDecimalInt(int decInt);
        string getBDI();
        BigDecimalInt operator+ (BigDecimalInt anotherDec);
};

