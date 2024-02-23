#include <iostream>
#include <cstring>

int main() {
    int x = 10;

/*preinkrementacja powoduje zwiększenie wartości zmiennej o jeden, ale jej zwiększenie następuje PRZED wykorzystaniem zmiennej*/
    std::cout << "Przed inkrementacją x: " << x << std::endl;
    int y = ++x; //NAJPIERW zostanie zwiększona wartość zmiennej x o jeden, a następnie zostanie użyta wartość 11
    std::cout << "Po inkrementacji: " << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
}