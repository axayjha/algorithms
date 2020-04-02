#include <iostream>
#include <limits.h>
using namespace std;

class MinHeap {
        int *harr;
        int capacity;
        int heap_size;
        public:
        MinHeap(int arr[], int size);
        void MinHeapify(int i); // to minify subtree rooted with index i
        int parent(int i) { return (i-1)/2;}
        int left(int i) {return 2*i + 1;}
        int right(int i) {return 2*i + 2;}
        int extractMin();
        int getMin() {return harr[0];}
};

MinHeap::MinHeap(int arr[], int size) {
        this->heap_size = size;
        this->harr = arr;
        int i = (heap_size - 1)/2;
        while (i >= 0) {
                MinHeapify(i);
                i--;
        }
}

int MinHeap :: extractMin() {
        if (this->heap_size == 0)
                return INT_MAX;
        int res = this->harr[0];

        if (heap_size > 1) {
                harr[0] = harr[heap_size-1];
                MinHeapify(0);
        }
        heap_size--;      
        return res;
}

void MinHeap :: MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[smallest])
                smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
                smallest = r;
        if (smallest != i) {
                swap(&harr[i], &harr[smallest]);
                MinHeapify(smallest);
        }               
}