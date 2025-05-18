#include <iostream>
using namespace std;

void InsertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    InsertionSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}

