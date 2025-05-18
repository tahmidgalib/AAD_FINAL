#include <iostream>
using namespace std;

int partitionn(int A[], int l, int h) {
    int pivot = A[l];
    int i = l;
    int j = h;

    while (i < j) {
        while (i <= h && A[i] <= pivot) {
            i++;
        }
        while (j >= l && A[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(A[i], A[j]);
        }
    }
    swap(A[l], A[j]);
    return j;
}

void Quicksort(int A[], int l, int h) {
    if (l < h) {
        int j = partitionn(A, l, h);
        Quicksort(A, l, j - 1);
        Quicksort(A, j + 1, h);
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

    Quicksort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}

