#include <iostream>
#include <cstring>

int main() {
    int x = 10;

/*postinkrementacja powoduje zwiększenie wartości zmiennej o jeden, ale jej zwiększenie następuje PO wykorzystaniu zmiennej*/
    std::cout << "Przed inkrementacją x: " << x << std::endl;
    int y = x++; ////NAJPIERW zostanie użyta wartość 10, a następnie zmienna x zostanie zwiększona o jeden
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
}