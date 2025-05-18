#include <iostream>
using namespace std;


int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

int parent(int i) {
    return i / 2;
}

void max_heapify(int heap[], int heap_size, int i) {
    int l = left(i);
    int r = right(i);
    int largest;

    if (l <= heap_size && heap[l] > heap[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if (r <= heap_size && heap[r] > heap[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        max_heapify(heap, heap_size, largest);
    }
}

void build_max_heap(int heap[], int heap_size) {
    for (int i = heap_size / 2; i >= 1; i--) {
        max_heapify(heap, heap_size, i);
    }
}

void heap_sort(int heap[], int heap_size) {
    build_max_heap(heap, heap_size);

    for (int i = heap_size; i > 1; i--) {
        swap(heap[1], heap[i]);
        heap_size--;
        max_heapify(heap, heap_size, 1);
    }
}

int main() {
    int heap_size;
    cout << "Enter heap size: ";
    cin >> heap_size;

    int heap[heap_size + 1];

    cout << "Enter heap elements: ";
    for (int i = 1; i <= heap_size; i++) {
        cin >> heap[i];
    }

    cout << "Original array: ";
    for (int i = 1; i <= heap_size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    heap_sort(heap, heap_size);

    cout << "Sorted array: ";
    for (int i = 1; i <= heap_size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;

}
