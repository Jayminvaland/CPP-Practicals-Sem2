#include <iostream>
#include <vector>
#include <set>
#include <iterator>
int main() {
    int n, temp;
    std::set<int> uniqueElements;

    std::cout << "Enter the number of integers: ";
    if (!(std::cin >> n)) return 1;

    std::cout << "Enter " << n << " integers (including duplicates): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        uniqueElements.insert(temp);
    }
    std::vector<int> result(uniqueElements.begin(), uniqueElements.end());
    std::cout << "\nUnique elements in sorted order (using iterators):" << std::endl;
    std::set<int>::iterator it;
    for (it = uniqueElements.begin(); it != uniqueElements.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\nTotal unique count: " << result.size() << std::endl;
    return 0; 
}