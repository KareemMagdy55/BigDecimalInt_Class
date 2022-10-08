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

