#pragma once
#include <vector>
#include <deque>
using namespace std;

class BigDecimalInt{
    private:
        string BDI ;
        deque<int> add(vector<int> bdi1,vector<int> bdi2,int maxlen);
        deque<int> sub(vector<int> bdi1,vector<int> bdi2,int maxlen);

public:
        BigDecimalInt(string decStr);
        BigDecimalInt(int decInt);
        string getBDI();
        bool check (BigDecimalInt anotherDec);
        BigDecimalInt operator+ (BigDecimalInt anotherDec);
        BigDecimalInt operator- (BigDecimalInt anotherDec);
        bool operator> (BigDecimalInt anotherDec);
        bool operator< (BigDecimalInt anotherDec);
        bool operator==(BigDecimalInt anotherDec);
        int size();
        int sign();
        friend ostream& operator << (ostream& out, BigDecimalInt b);
};

