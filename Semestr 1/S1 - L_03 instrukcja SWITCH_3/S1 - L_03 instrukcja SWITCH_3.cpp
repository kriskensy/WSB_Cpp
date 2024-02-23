#include <iostream>

int main() {
    float a,b;
    char wybor;

    std::cout << "Podaj pierwszą liczbę: " << std::endl;
    std::cin >> a;
    std::cout << "Podaj drugą liczbę: " << std::endl;
    std::cin >> b;

    std::cout << "Wybierz '+' aby dodać:" << std::endl;
    std::cout << "Wybierz '-' aby odjąć:" << std::endl;
    std::cout << "Wybierz '*' aby pomnożyć:" << std::endl;
    std::cout << "Wybierz '/' aby podzielić:" << std::endl;
    std::cin >> wybor;

    switch(wybor) {
        case '+': std::cout << "Suma wynosi: " << a+b; break;
        case '-': std::cout << "Różnica wynosi: " << a-b; break;
        case '*': std::cout << "Iloczyn wynosi: " << a*b; break;
        case '/': std::cout << "Iloraz wynosi: " << a/b; break;
        default: std::cout << "Niepoprawna opcja!";
    }
}