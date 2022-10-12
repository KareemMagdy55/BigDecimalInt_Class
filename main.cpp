#include <iostream>
#include "BDI.cpp"

int main() {
    BigDecimalInt x("999");
    BigDecimalInt y("800");
    BigDecimalInt z(x + y);

//    cout << z.getBDI() <<'\n';
//    cout << z.size() << endl ;
    cout << (z > x) ;
}
