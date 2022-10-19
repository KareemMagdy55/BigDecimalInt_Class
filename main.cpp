#include <iostream>
#include "BDI.cpp"

int main() {
BigDecimalInt x("-121");
BigDecimalInt y("-121");
BigDecimalInt z(x-y);
    BigDecimalInt num4 = x - y;
    cout <<num4<<'\n';
//z = x;
cout  << z<<'\n';
//if(x < y){cout << "y is bigger";}
//else cout <<"x is bigger";

}
