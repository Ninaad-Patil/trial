#include <iostream>
#include <vector>
#include <thread>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int factor = 2;

    auto multiply = [factor](int x) { return x * factor; };
    
    // Use a lambda to parallelize the multiplication
    std::vector<int> results;
    std::vector<std::thread> threads;
    
    for (int num : numbers) {
        threads.emplace_back([num, &multiply, &results]() {
            results.push_back(multiply(num));
        });
    }
    
    for (auto& thread : threads) {
        thread.join();
    }
    
    for (int result : results) {
        std::cout << result << " ";
    }
    std::cout << std::endl;

    return 0;
}
