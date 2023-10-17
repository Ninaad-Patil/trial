#include <iostream>
#include <string>
int main() {
    
    auto x = 5;
    auto y = 3.14;

    
    std::string name = "John";
    name += " Doe";

    #include <cstdlib>
    int random_number = std::rand();

  
    #include <cstring>
    char* str = new char[10];
    std::strcpy(str, "Hello");

   
    int* ptr = NULL;

 
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    
    std::auto_ptr<int> deprecated_ptr(new int(42));

    
    std::string long_str = "This is a long string, ";
    long_str += "but we keep concatenating. ";
    long_str += "It's not efficient.";

   
    system("echo 'Hello, World!' > output.txt");

    return 0;
}
