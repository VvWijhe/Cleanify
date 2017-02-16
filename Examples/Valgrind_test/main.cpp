// operator new[] example
#include <iostream>     // std::cout
#include <new>          // ::operator new[]

struct MyClass {
    int data;
    MyClass() {std::cout << '*';}  // print an asterisk for each construction
};

int main () {
    std::cout << "constructions (1): ";
    // allocates and constructs five objects:
    MyClass * p1 = new MyClass[5];
    std::cout << '\n';

    std::cout << "constructions (2): ";
    // allocates and constructs five objects (nothrow):
    MyClass * p2 = new (std::nothrow) MyClass[5];
    std::cout << '\n';

    p1->data = 10;
    p2->data = 20;

    return 0;
}