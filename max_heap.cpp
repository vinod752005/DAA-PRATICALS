#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& heap, int size, int index) {
    int maxIndex = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[maxIndex]) {
        maxIndex = left;
    }

    if (right < size && heap[right] > heap[maxIndex]) {
        maxIndex = right;
    }

    if (maxIndex != index) {
        swap(heap[index], heap[maxIndex]);
        heapify(heap, size, maxIndex);
    }
}

void insert(vector<int>& heap, int val) {
    heap.push_back(val);
    int curr = heap.size() - 1;

    while (curr > 0) {
        int parent = (curr - 1) / 2;
        if (heap[curr] > heap[parent]) {
            swap(heap[curr], heap[parent]);
            curr = parent;
        } else {
            break;
        }
    }
}

int extractMax(vector<int>& heap) {
    if (heap.empty()) {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty()) {
        heapify(heap, heap.size(), 0);
    }

    return maxVal;
}

int main() {
    vector<int> heap;
    int n, num;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        insert(heap, num);
    }

    cout << "\nMax Heap: ";
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Maximum element: " << heap[0] << endl;

    cout << "Extracting Max: " << extractMax(heap) << endl;

    cout << "Heap after extraction: ";
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}