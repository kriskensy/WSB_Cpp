#include <iostream> 
#include <stack> 
   
void showstack(std::stack <int> stack) 
{ 
    while (!stack.empty()) 
    { 
        std::cout << " " << stack.top(); 
        stack.pop(); 
    } 
    std::cout << std::endl; 
} 
   
int main () 
{ 
    std::stack <int> stack; 
    stack.push(10); 
    stack.push(30); 
    stack.push(20); 
    stack.push(5); 
    stack.push(19); 
   
    std::cout << "The stack is: "; 
    showstack(stack); 
   
    std::cout << "ilosc elementow w stosie: " << stack.size() << std::endl; 
    std::cout << "najnowszy element w stosie: " << stack.top() << std::endl; 
   
    std::cout << "Najnowszy element " << stack.top() << " zostal zdjety ze stosu." << std::endl;
    stack.pop();
    std::cout << "Teraz stos wyglada tak: ";
    showstack(stack); 
   
    return 0; 
}