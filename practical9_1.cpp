#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, val;
    std::vector<int> vec;

    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        vec.push_back(val);
    }

    
    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.end();
    
    
    if (!vec.empty()) {
        --end; 
        while (start < end) {
            std::iter_swap(start, end);
            ++start;
            --end;
        }
    }

    std::cout << "After Manual Reversal: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    std::reverse(vec.begin(), vec.end());
    std::cout << "After std::reverse (back to original): ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}