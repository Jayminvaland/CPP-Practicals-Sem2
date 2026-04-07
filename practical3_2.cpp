#include <iostream>
#include <ctime>  
using namespace std;


int recursiveSum(int arr[], int n) {
    if (n <= 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}


int iterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    
    int* arr = new int[n];


    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   
    clock_t start1 = clock();
    int recSum = recursiveSum(arr, n);
    clock_t end1 = clock();
    double recTime = double(end1 - start1) / CLOCKS_PER_SEC;


    clock_t start2 = clock();
    int itrSum = iterativeSum(arr, n);
    clock_t end2 = clock();
    double itrTime = double(end2 - start2) / CLOCKS_PER_SEC;

    
    cout << "\nRecursive Sum = " << recSum;
    cout << "\nTime (Recursive) = " << recTime << " seconds";

    cout << "\n\nIterative Sum = " << itrSum;
    cout << "\nTime (Iterative) = " << itrTime << " seconds";

    
    delete[] arr;

    return 0;
}