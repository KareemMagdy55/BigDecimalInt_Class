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
        BigDecimalInt operator- (BigDecimalInt anotherDec);
        bool operator> (BigDecimalInt anotherDec);
        bool operator< (BigDecimalInt anotherDec);
        bool operator==(BigDecimalInt anotherDec);
        int size();
        int sign();
        friend ostream& operator << (ostream& out, BigDecimalInt b);
};

