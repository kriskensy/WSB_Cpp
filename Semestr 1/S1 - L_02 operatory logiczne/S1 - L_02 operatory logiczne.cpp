#include <iostream>

int main () {
    bool p = 1;
    bool q = 0;

    std::cout << "p=(true) " << p << " , q=(false) " << q << std::endl;
    std::cout << std::endl;

    std::cout << "p && q = " << (p && q) << std::endl;
    std::cout << "p || q = " << (p || q) << std::endl;
    std::cout << "p ^ q = " << (p ^ q) << std::endl; //jeśli dane bity są różne to jeden, jeżeli są takie same to 0
    std::cout << "!q = " << !q << std::endl;
    std::cout << std::endl;
//TODO: brakuje jakiejś biblioteki, że operatory słowne nie działają??
/*    std::cout << "p and q = " << (p and q) << std::endl;
    std::cout << "p or q = " << (p or q) << std::endl;
    std::cout << "p xor q = " << (p xor q) << std::endl; //jeśli dane bity są różne to jeden, jeżeli są takie same to 0
    std::cout << "not q = " << not q << std::endl;*/
}