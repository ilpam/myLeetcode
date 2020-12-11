#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

#define left(x) (2*(x)+1)
#define right(x) (2*(x)+2)

void sink(vector<int> &heap, int n, int k)   // [0, n)
{
    while (left(k) < n) {
        int maxPos = left(k);
        if (right(k) < n && heap[right(k)] > heap[left(k)]) {
            maxPos = right(k);
        }
        if (heap[k] > heap[maxPos]) break;
        swap(heap[k], heap[maxPos]);
        k = maxPos;
    }
}

void heapSort(vector<int> &array) 
{
    int n = array.size();
    for (int i = n/2; i >= 0; i--) {
        sink(array, n, i);
    }
    while (n >= 1) {
        swap(array[0], array[n-1]);
        sink(array, n-1, 0);
        --n;
    }
}


int main()
{
    vector<int> array{9, 5, 3, 1, 2, 7, 6, 0, 8, 4};
    heapSort(array);
    for (const auto &i : array) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}