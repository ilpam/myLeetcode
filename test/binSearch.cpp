#include <cstdio>

// 代码中 left + (right - left) / 2 就和 (left + right) / 2 的结果相同，但是有效防止了 left 和 right 太大直接相加导致溢出
// 以下是[lo, hi)
int binarySearch(vector<int> &array, int target)
{
    int lo = 0, hi = array.size();
    int mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (arrry[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}

//下面是开区间情况下，寻找左右边界的二分查找

int leftBound(vector<int> &array, int target)
{
    int lo = 0, hi = array.size();
    int mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (arrry[mid] == target) {
            right = mid;
        } else if (array[mid] > target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (lo < array.size() && array[lo] == target) return lo;
    return -1; 
}

int rightBound(vector<int> &array, int target)
{
    int lo = 0, hi = array.size();
    int mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (arrry[mid] == target) {
            lo = mid + 1;
        } else if (array[mid] > target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (lo > 0 && array[lo-1] == target) return lo-1;
    return -1; 
}

int main()
{

}