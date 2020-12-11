#include <cstdio>
#include <vector>
using namespace std;

#define parent(x) ((x)/2)
#define left(x) ((x)*2)
#define right(x) ((x)*2+1)

// index 1 as root
class maxPQ {
public:
    maxPQ(int n):data(n+1, 0),lastIdx(0){}
    ~maxPQ();
    int getMax();
    void delMax();
    void insert(int x);
private:
    vector<int> data;
    int lastIdx;
    void swim(int k);
    void sink(int k);
};

// index k up
void maxPQ::swim(int k) {
    while (k > 1) {
        if (data[k] > data[parent(k)]) {
            swap(data[k], data[parent(k)]);
        }
        k = parent(k);
    }
}

//index k down
void maxPQ::sink(int k) {
    while (left(k) <= lastIdx) {
        int maxPos = left(k);
        if (right(k) <= lastIdx) {
            if (data[right(k)] > data[left(k)]) maxPos = right(k);
        }
        if (data[k] > data[right(k)]) break; //compare with max child, to check if need sink
        swap(data[k], data[maxPos]);
        k = maxPos;
    }
}

int maxPQ::getMax() {
    return data[1];
}

void maxPQ::insert(int x) {
    ++lastIdx;
    data[lastIdx] = x;
    swim(lastIdx);
}

void maxPQ::delMax() {
    swap(data[1], data[lastIdx]);
    --lastIdx;
    sink(1);
}

void constuctHeap_down(vector<int> &data) {
    for (int i)
}

void constuctHeap_up(vector<int> &data) {
}
