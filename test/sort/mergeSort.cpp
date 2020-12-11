#include <cstdio>
#include <vector>
using namespace std;

// merge [lo,mid) and [mid,hi)
void merge(vector<int> &nums, int lo, int mid, int hi)  
{
    vector<int> aux(hi-mid, 0);
    for (int i = hi-1, j = hi-mid-1; i >= mid; --i, --j) {
        aux[j] = nums[i];
    }

    int i = mid - 1, j = aux.size()-1, k = hi -1;
    while (i >= lo && j >= 0) 
        nums[k--] = nums[i] > aux[j] ? nums[i--] : aux[j--];
    while (j >= 0)
        nums[k--] = aux[j--];
}

void mergeSort(vector<int> &nums, int lo, int hi)
{
    if (hi - lo < 2) return;
    int mid = lo + (hi-lo)/2;
    mergeSort(nums, lo, mid);
    mergeSort(nums, mid, hi);
    merge(nums, lo, mid, hi);
} 

int main()
{
    vector<int> nums{1,3,3,9,2,5,3,7,10,8,4,0};
    mergeSort(nums, 0, nums.size());
    for (auto i : nums) {
        printf("%d ", i);
    }
    return 0;
}