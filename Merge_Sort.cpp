#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int temp[10];

    while (i <= mid && j <= h) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
            k++;
        } else {
            temp[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= h) {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (k = l; k <= h; k++) {
        a[k] = temp[k];
    }
}

void mergesort(int a[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergesort(a, 0, n - 1);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
