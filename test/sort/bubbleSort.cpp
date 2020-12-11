#include <vector>
#include <cstdio>

using std::vector;

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(vector<int> &array) 
{
    bool sorted = false;
    int len = array.size();
    while (len && !sorted) {
        sorted = true;
        for (int i = 1; i < len; ++i) {
            if (array[i] < array[i-1]) {
                swap(array[i], array[i-1]);
                sorted = false;
            }
        }
        len--;
    }
}

int main()
{
    vector<int> array{9, 5, 3, 1, 2, 7, 6, 0, 8, 4};
    bubbleSort(array);
    for (const auto &i : array) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}