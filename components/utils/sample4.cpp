#include <iostream>
#include <vector>

// Define a variable template
template <typename T>
constexpr T pi = T(3.1415926535897932385);

int main() {
    std::cout << "Value of pi (double): " << pi<double> << std::endl;
    std::cout << "Value of pi (float): " << pi<float> << std::endl;

    // Use a C++14 feature: generic lambdas
    auto print = [](auto value) {
        std::cout << "Value: " << value << std::endl;
    };

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (int num : numbers) {
        print(num);
    }

    return 0;
}
