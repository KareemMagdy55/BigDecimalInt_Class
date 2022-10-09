#include <iostream>
#include "BDI.cpp"

int main() {
    BigDecimalInt x("999");
    BigDecimalInt y("999");
    BigDecimalInt z(x + y);

    cout << z.getBDI() ;
}
