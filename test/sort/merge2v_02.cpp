// used for merge sort
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

int main()
{
    vector<int> nums{1,3,5,7,9,2,4,6,8,10};
    merge(nums, 0, 5, 10);
    for (auto i : nums) {
        printf("%d ", i);
    }
}

