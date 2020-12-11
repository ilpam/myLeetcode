
#include <cstdio>
#include <vector>

using namespace std;

void shellSort(vector<int> &nums)
{
    int len = nums.size();
    int h = 1;
    while (h < len/3) h = 3*h + 1;
    while (h >= 1) {
        for (int i = h; i < len; ++i) {
            for (int j = i; j >= h && nums[j] < nums[j-h]; j-=h) {
                swap(nums[j], nums[j-h]);
            }
        }
        h /= 3;
    }

}



int main()
{

}