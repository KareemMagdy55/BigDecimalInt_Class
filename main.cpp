#include <iostream>
#include "BDI.cpp"

int main() {
BigDecimalInt x("1000000000000");
BigDecimalInt y("10000000000001");
BigDecimalInt z(x+y);
cout <<z<<'\n';
z = x;
cout  << z<<'\n';
if(x < y){cout << "y is bigger";}
else cout <<"x is bigger";

}
