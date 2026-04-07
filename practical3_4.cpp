#include <iostream>
using namespace std;

template <class T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


template <class T>
T findMax(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}


template <class T>
void reverseArray(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}


template <class T>
void findLeaders(T arr[], int n) {
    cout << "Leader elements: ";
    
    T leader = arr[n - 1];
    cout << leader << " ";

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > leader) {
            leader = arr[i];
            cout << leader << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    
    int intArr[100];
    cout << "\nEnter integer array:\n";
    for (int i = 0; i < n; i++) cin >> intArr[i];

    
    float floatArr[100];
    cout << "\nEnter float array:\n";
    for (int i = 0; i < n; i++) cin >> floatArr[i];

    
    char charArr[100];
    cout << "\nEnter character array:\n";
    for (int i = 0; i < n; i++) cin >> charArr[i];

    
    cout << "\n--- Integer Array ---\n";
    display(intArr, n);
    cout << "Maximum: " << findMax(intArr, n) << endl;
    reverseArray(intArr, n);
    cout << "Reversed: ";
    display(intArr, n);
    findLeaders(intArr, n);

   
    cout << "\n--- Float Array ---\n";
    display(floatArr, n);
    cout << "Maximum: " << findMax(floatArr, n) << endl;
    reverseArray(floatArr, n);
    cout << "Reversed: ";
    display(floatArr, n);
    findLeaders(floatArr, n);

   
    cout << "\n--- Character Array ---\n";
    display(charArr, n);
    cout << "Maximum (ASCII): " << findMax(charArr, n) << endl;
    reverseArray(charArr, n);
    cout << "Reversed: ";
    display(charArr, n);
    findLeaders(charArr, n);
    return 0;
}