#include <iostream>

template<typename T>
struct X {
    static int a;
    static int b;
};

// Attempt to create a pointer to X<int>::a without any prior usage of X<int>
int* p = &X<int>::a;  // This will likely result in a "not defined" error

int main() {
    // Usage of X<int>::b does not require an instance of X<int> to be defined
    std::cout << X<int>::b << std::endl;  // This will not result in an error
    
    return 0;
}
