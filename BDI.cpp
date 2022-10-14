#include "BDI.h"
#include <regex>


BigDecimalInt::BigDecimalInt(string decStr){
    regex chkInt ("[+-]?[0-9]+");

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

    int maxlen = max(BDI.length(),anotherDec.getBDI().length());
    vector<int> bdi1(maxlen,0);
    vector<int> bdi2(maxlen,0);

    deque<int> total;
    for(int i = 0 ; i<BDI.length(); i++ ){
        bdi1[bdi1.size()-i-1] = (BDI[BDI.size()-1-i] - 48);
      //  cout << bdi1[i];
    }
   // cout <<'\n';
    for(int i = 0 ; i <anotherDec.getBDI().length(); i++ ){
        bdi2[bdi2.size()-i-1] = (anotherDec.getBDI()[anotherDec.getBDI().size()-1-i] - 48);
       // cout << bdi2[i];
    }

    int sum = 0 ;
    for(int i = 0 ; i < maxlen   ; i++ ){
        sum += (bdi1[bdi1.size()-1-i] + bdi2[bdi2.size()-1-i]);
        int carry = sum % 10 ;
        sum /= 10  ;
        total.push_front(carry) ;
    }
   /* if ( bdi1[0] + bdi2[0] > 10 )
        total.push_front((bdi1[0] + bdi2[0]) / 10 % 10 ) ;*/

    string str ;
    for ( int & i : total )
        str += (i + 48);

    BigDecimalInt totalBDI(str);
    return totalBDI;

}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{
    int maxlen = max(BDI.length(),anotherDec.getBDI().length());
    vector<int> bdi1(maxlen,0);
    vector<int> bdi2(maxlen,0);

    deque<int> total;
    for(int i = 0 ; i<BDI.length(); i++ ){
        bdi1[bdi1.size()-i-1] = (BDI[BDI.size()-1-i] - 48);
        //  cout << bdi1[i];
    }
    // cout <<'\n';
    for(int i = 0 ; i <anotherDec.getBDI().length(); i++ ){
        bdi2[bdi2.size()-i-1] = (anotherDec.getBDI()[anotherDec.getBDI().size()-1-i] - 48);
        // cout << bdi2[i];
    }

};


bool BigDecimalInt:: operator> (BigDecimalInt anotherDec){

    int maxLen = max ( BDI.length() , anotherDec.getBDI().length());
    deque<int> bdi1;
    deque<int> bdi2;

    for(char& ch : BDI){
        bdi1.push_back(ch - 48);
    }
    for(char& ch : anotherDec.getBDI()){
        bdi2.push_back(ch - 48);
    }
    int minLen = min(bdi1.size(), bdi2.size()) ;
    for (int i = minLen; i < maxLen; ++i) {
        (bdi1.size() > bdi2.size() ? bdi2 : bdi1).push_front(0);
    }

    for (int i = 0; i < maxLen; ++i) {
        if ( bdi1[i] > bdi2[i]) return true;
        else if ( bdi1[i] < bdi2[i]) return false;

    }
    return false;

}

bool BigDecimalInt:: operator< (BigDecimalInt anotherDec){

    int maxLen = max ( BDI.length() , anotherDec.getBDI().length());
    deque<int> bdi1;
    deque<int> bdi2;

    for(char& ch : BDI){
        bdi1.push_back(ch - 48);
    }
    for(char& ch : anotherDec.getBDI()){
        bdi2.push_back(ch - 48);
    }
    int minLen = min(bdi1.size(), bdi2.size()) ;
    for (int i = minLen; i < maxLen; ++i) {
        (bdi1.size() > bdi2.size() ? bdi2 : bdi1).push_front(0);
    }

    for (int i = 0; i < maxLen; ++i) {
        if ( bdi1[i] < bdi2[i]) return true;
        else if ( bdi1[i] > bdi2[i]) return false;

    }
    return false;


}



bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {

    int maxLen = max ( BDI.length() , anotherDec.getBDI().length());
    deque<int> bdi1;
    deque<int> bdi2;

    for(char& ch : BDI){
        bdi1.push_back(ch - 48);
    }
    for(char& ch : anotherDec.getBDI()){
        bdi2.push_back(ch - 48);
    }
    int minLen = min(bdi1.size(), bdi2.size()) ;
    for (int i = minLen; i < maxLen; ++i) {
        (bdi1.size() > bdi2.size() ? bdi2 : bdi1).push_front(0);
    }

    for (int i = 0; i < maxLen; ++i) {
        if ( bdi1[i] != bdi2[i]) return false;

    }
    return true;


}


int BigDecimalInt::size() {
    return BDI.length();
}
int BigDecimalInt::sign() {
    return (BDI[0] == '-' ? -1 : 1);
}

 ostream& operator << (ostream& out, BigDecimalInt b){
    out << b.getBDI();
    return out ;
}


