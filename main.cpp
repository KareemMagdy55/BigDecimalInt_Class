#include <iostream>
#include "BDI.cpp"

int main() {
    BigDecimalInt x("300");
    BigDecimalInt y("200");
    BigDecimalInt z(x + y);

    cout << z.getBDI() ;
}
