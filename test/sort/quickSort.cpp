
#include <cstdio>
#include <vector>

using namespace std;

void quickSort(vector<int> &nums)
{
    int lo = 0, hi = nums.size();
    quickSortHelper(nums, lo, hi);   // sort [lo,hi)
}

int partition(vector<int> &nums, int lo, int hi)  // partition [lo,hi] 
{
    swap(nums[lo], nums[lo + rand() % (hi - lo + 1)]);
    int pivot = nums[lo];
    while (hi > lo) {
        while ((hi > lo) && (nums[hi] >= pivot)) hi--; 
        nums[lo] = nums[hi];
        while ((hi > lo) && (nums[lo] <= pivot)) lo++;
        nums[hi] = nums[lo];
    }
    //assert(lo == hi);
    nums[lo] = pivot;
    return lo;
}

void quickSortHelper(vector<int> &nums, int lo, int hi)
{
    int mid = partition(nums, lo, hi - 1);
    quickSortHelper(nums, lo, mid);
    quickSortHelper(nums, mid + 1, hi);
}

int main()
{

}