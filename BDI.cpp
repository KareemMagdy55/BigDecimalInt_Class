#include "BDI.h"
#include <regex>

deque<int> BigDecimalInt::add(vector<int> bdi1, vector<int> bdi2,int maxlen){
    deque<int> total;

int sum = 0;
for (int i = 0; i < maxlen; i++) {
sum += (bdi1[bdi1.size() - 1 - i] + bdi2[bdi2.size() - 1 - i]);
if(i == maxlen-1)
{total.push_front(sum);
}
else{int carry = sum % 10;
    sum /= 10;
    total.push_front(carry);}

}
/* if ( bdi1[0] + bdi2[0] > 10 )
     total.push_front((bdi1[0] + bdi2[0]) / 10 % 10 ) ;*/
    return total;
}

deque<int> BigDecimalInt::sub(vector<int> bdi1, vector<int> bdi2, int maxlen) {
    deque<int> total;

for(int i=0;i<maxlen; i++){
    int count =1;
    if(bdi2[bdi2.size() - 1 - i]>=bdi1[bdi1.size() - 1 - i]){
        total.push_front(bdi2[bdi2.size() - 1 - i]-bdi1[bdi1.size() - 1 - i]);
    }
    else{
        while (bdi2[bdi2.size() - 1 - i-count] == 0)
        {
            bdi2[bdi2.size() - 1 - i - count] += 9;
            count+=1;
        }
        bdi2[bdi2.size() - 1 - i- count] -= 1;

        total.push_front((bdi2[bdi2.size() - 1 - i]+10)-bdi1[bdi1.size() - 1 - i]);
    }

}
    return total;
}


BigDecimalInt::BigDecimalInt(string decStr){
    regex chkInt ("[+-]?[0-9]+");

    while (!regex_match(decStr, chkInt)) {
        cout << "\nInvalid input, please input another one : ";
        cin >> decStr ;
    }

    if(decStr[0] != '+' && decStr[0] != '-')
    {
        BDI+='+';
    }
    for (int i = 0; i < decStr.length() ; ++i) {
        BDI += decStr[i] ;
    }

}

BigDecimalInt::BigDecimalInt(int decInt) {
    BDI = to_string(decInt);
}

string BigDecimalInt::getBDI() {
    return BDI ;
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    if((BDI[0] == '-' && anotherDec.getBDI()[0] == '-')){

        int maxlen = max(BDI.length(), anotherDec.getBDI().length())-1;
        vector<int> bdi1(maxlen, 0);
        vector<int> bdi2(maxlen, 0);
        for (int i = 0; i < BDI.length()-1; i++) {
            bdi1[bdi1.size() - i - 1] = (BDI[BDI.size() - 1 - i] - 48);
//  cout << bdi1[i];
        }
// cout <<'\n';
        for (int i = 0; i < anotherDec.getBDI().length()-1; i++) {
            bdi2[bdi2.size() - i - 1] = (anotherDec.getBDI()[anotherDec.getBDI().size() - 1 - i] - 48);
// cout << bdi2[i];
        }
        deque<int> total = add(bdi1,bdi2,maxlen);

        string str;
        str += '-';
        for (int &i: total)
            str += (to_string(i));

        BigDecimalInt totalBDI(str);
        return totalBDI;
    }
    else if((BDI[0] == '+' && anotherDec.getBDI()[0] == '+')){

        int maxlen = max(BDI.length(), anotherDec.getBDI().length())-1;
        vector<int> bdi1(maxlen, 0);
        vector<int> bdi2(maxlen, 0);
        for (int i = 0; i < BDI.length()-1; i++) {
            bdi1[bdi1.size() - i - 1] = (BDI[BDI.size() - 1 - i] - 48);
//  cout << bdi1[i];
        }
// cout <<'\n';
        for (int i = 0; i < anotherDec.getBDI().length()-1; i++) {
            bdi2[bdi2.size() - i - 1] = (anotherDec.getBDI()[anotherDec.getBDI().size() - 1 - i] - 48);
// cout << bdi2[i];
        }
        deque<int> total = add(bdi1,bdi2,maxlen);

        string str;
        str += '+';
        for (int &i: total)
            str += (to_string(i));

        BigDecimalInt totalBDI(str);
        return totalBDI;
    }
    else if((BDI[0] == '+' && anotherDec.getBDI()[0] == '-')){

        int maxlen = max(BDI.length(), anotherDec.getBDI().length())-1;
        vector<int> bdi1(maxlen, 0);
        vector<int> bdi2(maxlen, 0);
        for (int i = 0; i < BDI.length()-1; i++) {
            bdi1[bdi1.size() - i - 1] = (BDI[BDI.size() - 1 - i] - 48);
//  cout << bdi1[i];
        }
// cout <<'\n';
        for (int i = 0; i < anotherDec.getBDI().length()-1; i++) {
            bdi2[bdi2.size() - i - 1] = (anotherDec.getBDI()[anotherDec.getBDI().size() - 1 - i] - 48);
// cout << bdi2[i];
        }

        string str;
        BDI[0] = '0';
        anotherDec.setter('0');

        if(*this < anotherDec)
        {

            deque<int> total = sub(bdi1,bdi2,maxlen);

            str += '-';
            for (int &i: total)
                str += (to_string(i));

        }

        else if(*this == anotherDec){
            BDI[0] = '+';
            anotherDec.setter('-');
            BigDecimalInt totalBDI("0");
            return  totalBDI;

        }

        else{

            deque<int> total = sub(bdi2,bdi1,maxlen);
            str += '+';
            for (int &i: total)
                str += (to_string(i));


        }

        BDI[0] = '+';
        anotherDec.setter('-');

        BigDecimalInt totalBDI(str);
        return totalBDI;
    }
    else if((BDI[0] == '-' && anotherDec.getBDI()[0] == '+')){

        int maxlen = max(BDI.length(), anotherDec.getBDI().length())-1;
        vector<int> bdi1(maxlen, 0);
        vector<int> bdi2(maxlen, 0);
        for (int i = 0; i < BDI.length()-1; i++) {
            bdi1[bdi1.size() - i - 1] = (BDI[BDI.size() - 1 - i] - 48);
//  cout << bdi1[i];
        }
// cout <<'\n';
        for (int i = 0; i < anotherDec.getBDI().length()-1; i++) {
            bdi2[bdi2.size() - i - 1] = (anotherDec.getBDI()[anotherDec.getBDI().size() - 1 - i] - 48);
// cout << bdi2[i];
        }
        BDI[0] = '0';
        anotherDec.setter('0');

        string str;

        if(*this < anotherDec)
        {

            deque<int> total = sub(bdi1,bdi2,maxlen);

            str += '+';
            for (int &i: total)
                str += (to_string(i));

        }
        else if(*this == anotherDec){
            BDI[0] = '-';
            anotherDec.setter('+');
            BigDecimalInt totalBDI("0");
            return  totalBDI;
        }
        else{
            deque<int> total = sub(bdi2,bdi1,maxlen);

            str += '-';
            for (int &i: total)
                str += (to_string(i));


        }

        BDI[0] = '-';
        anotherDec.setter('+');

        BigDecimalInt totalBDI(str);
        return totalBDI;
    }
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec) {
    if((BDI[0] == '-' && anotherDec.getBDI()[0] == '-')){

        int maxlen = max(BDI.length(), anotherDec.getBDI().length())-1;
        vector<int> bdi1(maxlen, 0);
        vector<int> bdi2(maxlen, 0);
        for (int i = 0; i < BDI.length()-1; i++) {
            bdi1[bdi1.size() - i - 1] = (BDI[BDI.size() - 1 - i] - 48);
//  cout << bdi1[i];
        }
// cout <<'\n';
        for (int i = 0; i < anotherDec.getBDI().length()-1; i++) {
            bdi2[bdi2.size() - i - 1] = (anotherDec.getBDI()[anotherDec.getBDI().size() - 1 - i] - 48);
// cout << bdi2[i];
        }

        string str;
        BDI[0]= '0';
        anotherDec.setter('0');
        if(*this > anotherDec)
        {
            deque<int> total = sub(bdi2,bdi1,maxlen);

            str += '-';
            for (int &i: total)
                str += (to_string(i));

        }
        else if(*this == anotherDec){
            BigDecimalInt totalBDI("0");
            BDI[0]= '-';
            anotherDec.setter('-');
           return  totalBDI;
        }
        else{
            deque<int> total = sub(bdi1,bdi2,maxlen);

            str += '+';
            for (int &i: total)
                str += (to_string(i));


        }

        BDI[0]= '-';
        anotherDec.setter('-');

        BigDecimalInt totalBDI(str);
        return totalBDI;
    }
    else if((BDI[0] == '+' && anotherDec.getBDI()[0] == '+'))
    {

        int maxlen = max(BDI.length(), anotherDec.getBDI().length())-1;
        vector<int> bdi1(maxlen, 0);
        vector<int> bdi2(maxlen, 0);
        for (int i = 0; i < BDI.length()-1; i++) {
            bdi1[bdi1.size() - i - 1] = (BDI[BDI.size() - 1 - i] - 48);
//  cout << bdi1[i];
        }
// cout <<'\n';
        for (int i = 0; i < anotherDec.getBDI().length()-1; i++) {
            bdi2[bdi2.size() - i - 1] = (anotherDec.getBDI()[anotherDec.getBDI().size() - 1 - i] - 48);
// cout << bdi2[i];
        }
        BDI[0] = '0';
        anotherDec.setter('0');

        string str;

        if(*this < anotherDec)
        {

            deque<int> total = sub(bdi1,bdi2,maxlen);

            str += '-';
            for (int &i: total)
                str += (to_string(i));

        }
        else if(*this == anotherDec){
            BDI[0] = '+';
            anotherDec.setter('+');
            BigDecimalInt totalBDI("0");
            return  totalBDI;
        }
        else{
            deque<int> total = sub(bdi2,bdi1,maxlen);

            str += '+';
            for (int &i: total)
                str += (to_string(i));


        }

        BDI[0] = '+';
        anotherDec.setter('+');

        BigDecimalInt totalBDI(str);
        return totalBDI;
    }
    else if((BDI[0] == '-' && anotherDec.getBDI()[0] == '+')){

        int maxlen = max(BDI.length(), anotherDec.getBDI().length())-1;
        vector<int> bdi1(maxlen, 0);
        vector<int> bdi2(maxlen, 0);
        for (int i = 0; i < BDI.length()-1; i++) {
            bdi1[bdi1.size() - i - 1] = (BDI[BDI.size() - 1 - i] - 48);
//  cout << bdi1[i];
        }
// cout <<'\n';
        for (int i = 0; i < anotherDec.getBDI().length()-1; i++) {
            bdi2[bdi2.size() - i - 1] = (anotherDec.getBDI()[anotherDec.getBDI().size() - 1 - i] - 48);
// cout << bdi2[i];
        }
        deque<int> total = add(bdi1,bdi2,maxlen);

        string str;
        str += '-';
        for (int &i: total)
            str += (to_string(i));

        BigDecimalInt totalBDI(str);
        return totalBDI;
    }
    else if((BDI[0] == '+' && anotherDec.getBDI()[0] == '-')){

        int maxlen = max(BDI.length(), anotherDec.getBDI().length())-1;
        vector<int> bdi1(maxlen, 0);
        vector<int> bdi2(maxlen, 0);
        for (int i = 0; i < BDI.length()-1; i++) {
            bdi1[bdi1.size() - i - 1] = (BDI[BDI.size() - 1 - i] - 48);
        }
        for (int i = 0; i < anotherDec.getBDI().length()-1; i++) {
            bdi2[bdi2.size() - i - 1] = (anotherDec.getBDI()[anotherDec.getBDI().size() - 1 - i] - 48);

        }
        deque<int> total = add(bdi1,bdi2,maxlen);

        string str;
        str += '+';
        for (int &i: total)
            str += (to_string(i));

        BigDecimalInt totalBDI(str);
        return totalBDI;
    }
};

bool BigDecimalInt:: operator> (BigDecimalInt anotherDec){
    int sign1 = this->sign() ;
    int sign2 = anotherDec.sign() ;

    deque<int> bdi1;
    deque<int> bdi2;

    for(char& ch : BDI){
        if ( ch == '-' || ch == '+') continue;
        bdi1.push_back(ch - 48);
    }
    for(char& ch : anotherDec.getBDI()){
        if ( ch == '-' || ch == '+') continue;
        bdi2.push_back(ch - 48);
    }
    int maxLen = max (bdi1.size(), bdi2.size());
    int minLen = min(bdi1.size(), bdi2.size()) ;

    for (int i = minLen; i < maxLen; ++i) {
        (bdi1.size() > bdi2.size() ? bdi2 : bdi1).push_front(0);
    }

    for (int i = 0; i < maxLen; ++i) {
        if ( bdi1[i] * sign1  > bdi2[i] * sign2) return true;
        else if ( bdi1[i] * sign1 < bdi2[i] * sign2) return false;

    }
    return false;


}

bool BigDecimalInt:: operator< (BigDecimalInt anotherDec){
    int sign1 = this->sign() ;
    int sign2 = anotherDec.sign() ;

    deque<int> bdi1;
    deque<int> bdi2;

    for(char& ch : BDI){
        if ( ch == '-' || ch == '+') continue;
        bdi1.push_back(ch - 48);
    }

    for(char& ch : anotherDec.getBDI()){
        if ( ch == '-' || ch == '+') continue;
        bdi2.push_back(ch - 48);
    }

    int maxLen = max (bdi1.size(), bdi2.size());
    int minLen = min(bdi1.size(), bdi2.size()) ;

    for (int i = minLen; i < maxLen; ++i) {
        (bdi1.size() > bdi2.size() ? bdi2 : bdi1).push_front(0);
    }

    for (int i = 0; i < maxLen; ++i) {
        if ( bdi1[i] * sign1  < bdi2[i] * sign2) return true;
        else if ( bdi1[i] * sign1 > bdi2[i] * sign2) return false;

    }
    return false;


}

bool BigDecimalInt:: operator== (BigDecimalInt anotherDec){
    int sign1 = this->sign() ;
    int sign2 = anotherDec.sign() ;

    deque<int> bdi1;
    deque<int> bdi2;

    for(char& ch : BDI){
        if ( ch == '-' || ch == '+') continue;
        bdi1.push_back(ch - 48);
    }
    for(char& ch : anotherDec.getBDI()){
        if ( ch == '-' || ch == '+') continue;
        bdi2.push_back(ch - 48);
    }
    int maxLen = max (bdi1.size(), bdi2.size());
    int minLen = min(bdi1.size(), bdi2.size()) ;

    for (int i = minLen; i < maxLen; ++i) {
        (bdi1.size() > bdi2.size() ? bdi2 : bdi1).push_front(0);
    }

    for (int i = 0; i < maxLen; ++i) {
        if ( bdi1[i] * sign1 != bdi2[i] * sign2) return false;

    }
    return true;


}

void BigDecimalInt::dltZeros() {

    for (int i = 0; i < BDI.length(); ++i) {
        if (!(BDI[i] - 48 ))
            BDI.erase(BDI[i]) ;
    }

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

void BigDecimalInt::setter(char a) {
    BDI[0] = a;
}