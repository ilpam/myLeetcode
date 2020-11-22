#include <cstdio>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &array)
{

}

void insertSort(vector<int> &array)
{
    for (int i = 0; i < array.size(); ++i) {
        for (int j = i+1; j < array.size(); ++j){
            
        }
    }
}

void shellSort(vector<int> &array)
{

}

void selectSort(vector<int> &array)
{

}

void quickSort(vector<int> &array)
{

}

void heapSort(vector<int> &array)
{

}

void merge(int lo, int mid, int hi)
{

}

void merge_sort(int lo, int hi)
{
    int mid = (lo + hi) / 2;
    if (hi - lo == 1) return;
    merge_sort(lo, mid);
    merge_sort(mid, hi);
    merge(lo, mid, hi);
}


void mergeSort(vector<int> &array)
{
    int len = array.size();
    merge_sort(0, len);
}



void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    return 0;
}