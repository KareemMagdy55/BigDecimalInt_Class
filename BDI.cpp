#include "BDI.h"
#include <regex>


BigDecimalInt::BigDecimalInt(string decStr){
    regex chkInt ("[0-9]+");

    while (!regex_match(decStr, chkInt)) {
        cout << "\nInvalid input, please input another one : ";
        cin >> decStr ;
    }

    BDI = decStr ;
}

BigDecimalInt::BigDecimalInt(int decInt) {
    BDI = to_string(decInt);
}

string BigDecimalInt::getBDI() {
    return BDI ;
}
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {

    int maxLen = max ( BDI.length() , anotherDec.getBDI().length());
    vector<int> bdi1(maxLen,0);
    vector<int> bdi2(maxLen,0);

    deque<int> total;
    for(int i = 0 ; i<BDI.length(); i++ ){
        bdi1[i] = BDI[i] - 48;
    }
    for(int i = 0 ; i <anotherDec.getBDI().length(); i++ ){
        bdi2[i] = anotherDec.getBDI()[i] - 48;
    }

    int sum = 0 ;
    for(int i = maxLen - 1 ; i >= 0; i-- ){
        sum += bdi1[i] + bdi2[i];
        int carry = sum % 10 ;
        sum = (sum / 10 ) % 10 ;
        total.push_front(carry) ;
    }
    string str ;
    for ( int & i : total )
        str += (i+48);

    BigDecimalInt totalBDI(str);
    return totalBDI;

}