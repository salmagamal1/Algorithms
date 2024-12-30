//By 'Salma Gamal Kamel' 20221073  created 10/21/2024
//updated 10/25/2024
//last update 10/27/2024

#include <iostream>
#include <vector>

using namespace std;

template<typename P, typename T>
class Heap {
private:
    vector<pair<P, T>> heap;

    // Helper function to maintain the heap property
    void heapify(int i);

public:
    Heap() = default;
    void insert(P priority, T value);
    pair<P, T> extractMax();
    pair<P, T> extractMin();
    void deleteElement(int idx);
    void print();
    void buildHeap(const vector<pair<P, T>>& arr);
    void heapSort(vector<pair<P, T>>& arr);
};

//-----------------------------------------------------------------------
// Helper function to maintain the heap property, O(logn)
template<typename P, typename T>
void Heap<P, T>::heapify(int i) {
    int largest = i;  // Start by assuming the largest element is the root.
    int l = 2 * i + 1;  // Left child index
    int r = 2 * i + 2;  // Right child index
    int size = heap.size();
    // If left child is larger than root
    if (l < size && heap[l].first > heap[largest].first)
        largest = l;  // Update largest to left child index
    // If right child is larger than largest
    if (r < size && heap[r].first > heap[largest].first)
        largest = r;  // Update largest to right child index

    if (largest != i) {  // If the largest is not the root, swap and heapify
        swap(heap[i], heap[largest]);  // Swap the root with the largest child
        heapify(largest);
    }
}



//-----------------------------------------------------------------------
// Insert a new element into the heap, O(logn)
template<typename P, typename T>
void Heap<P, T>::insert(P priority, T value) {
    heap.push_back({priority, value}); // Add the new element at the end of the heap
    int i = heap.size() - 1;

    // Ensure parent is larger than child
    while (i != 0 && heap[(i - 1) / 2].first < heap[i].first) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


//-----------------------------------------------------------------------
// Remove and return the maximum element, O(logn)
template<typename P, typename T>
pair<P, T> Heap<P, T>::extractMax() {
    if (heap.empty())
        throw underflow_error("Heap is underflow");

    if (heap.size() == 1) {
        pair<P, T> root = heap[0];
        heap.pop_back();
        return root;
    }

    pair<P, T> root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);

    return root;
}

//-----------------------------------------------------------------------
// New method to remove and return the minimum element, O(logn)
template<typename P, typename T>
pair<P, T> Heap<P, T>::extractMin() {
    if (heap.empty())
        throw underflow_error("Heap is underflow");

    if (heap.size() == 1) {
        pair<P, T> root = heap[0];
        heap.pop_back();
        return root;
    }

    pair<P, T> root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);

    return root;
}

//-----------------------------------------------------------------------
// Delete an element at a given index, O(logn)
template<typename P, typename T>
void Heap<P, T>::deleteElement(int idx) {
    if (idx < 0 || idx >= heap.size())
        throw out_of_range("Heap index out of range");

    heap[idx] = heap.back();
    heap.pop_back();

    if (idx < heap.size())
        heapify(idx);
}

//-----------------------------------------------------------------------
// Build a heap from an array, O(n)
template<typename P, typename T>
void Heap<P, T>::buildHeap(const vector<pair<P, T>>& arr) {
    heap = arr;
    // Start from the last non-leaf node and apply heapify to each node upwards
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        heapify(i);  // Apply heapify to each node
    }
}

//-----------------------------------------------------------------------
// Sort an array using heap sort based on priority, O(nlogn)
template<typename P, typename T>
void Heap<P, T>::heapSort(vector<pair<P, T>>& arr) {
    buildHeap(arr);  // Build max heap

    for (int i = arr.size() - 1; i >= 0; i--) {
        // Place current max at end of the array
        swap(arr[0], arr[i]);
        heap.pop_back();  // Simulate removing the last element
        heapify(0);
    }
}

//-----------------------------------------------------------------------
// Print all elements in the heap, O(n)
template<typename P, typename T>
void Heap<P, T>::print() {
    for (const auto& p : heap) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

//-----------------------------------------------------------------------
// Priority Queue class using a min heap (if you want)
template<typename P, typename T>
class PriorityQueue {
private:
    Heap<P, T> heap;

public:
    void insert(P priority, T value) {
        heap.insert(priority, value);
    }

    pair<P, T> extractHighestPriority() {
        return heap.extractMax();  // Change to extractMin if using a min-heap
    }

    pair<P, T> extractLowestPriority() {
        return heap.extractMin();  // For extracting the lowest priority
    }

    void print() {
        heap.print();
    }
};

//-----------------------------------------------------------------------
int main() {

    Heap<int, string> heap;


    cout << "Inserting elements into the heap:\n";
    heap.insert(10, "A");
    cout << "After inserting (10,A): ";
    heap.print();

    heap.insert(60, "B");
    cout << "After inserting (60,B): ";
    heap.print();

    heap.insert(15, "C");
    cout << "After inserting (15,C): ";
    heap.print();

    heap.insert(50, "D");
    cout << "After inserting (50,D): ";
    heap.print();

    heap.insert(40, "E");
    cout << "After inserting (40,E): ";
    heap.print();

    heap.insert(25, "F");
    cout << "After inserting (25,F): ";
    heap.print();

    // Extract the maximum element from the heap
    cout << "\nExtracting element from the heap (extractMax):\n";
    if (!heap.extractMax().second.empty()) {  // Check if the heap is not empty
        auto extractedMax = heap.extractMax();
        cout << "Extracted Max: (" << extractedMax.first << ", " << extractedMax.second << ")\n";
        cout << "Heap after extraction: ";
        heap.print();
    } else {
        cout << "Heap is empty.\n";
    }

    // Extract the minimum element from the heap
    cout << "\nExtracting element from the heap (extractMin):\n";
    if (!heap.extractMin().second.empty()) {  // Check if the heap is not empty
        auto extractedMin = heap.extractMin();
        cout << "Extracted Min: (" << extractedMin.first << ", " << extractedMin.second << ")\n";
        cout << "Heap after extraction: ";
        heap.print();
    } else {
        cout << "Heap is empty.\n";
    }

    // Heap sort
    vector<pair<int, string>> arr = {{10, "A"}, {20, "B"}, {15, "C"}, {30, "D"}, {50, "E"}};
    cout << "\nHeap Sort:\n";
    cout << "Original array:\n";
    for (const auto& p : arr) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    heap.heapSort(arr);

    cout << "Sorted array by priority:\n";
    for (const auto& p : arr) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout <<endl<<"------------------------------------------------------------"<< endl;



    PriorityQueue<int, string> pq;

    // Inserting elements into the priority queue
    cout << "Inserting elements into the priority queue:\n";
    pq.insert(10, "A");
    pq.insert(60, "B");
    pq.insert(15, "C");
    pq.insert(50, "D");
    pq.insert(40, "E");
    pq.insert(25, "F");
    pq.print();

    cout << "\nExtracting highest priority element:\n";
    auto highestPriority = pq.extractHighestPriority();
    cout << "Extracted: (" << highestPriority.first << ", " << highestPriority.second << ")\n";
    pq.print();


    return 0;
}