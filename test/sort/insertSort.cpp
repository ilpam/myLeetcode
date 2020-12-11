
#include <cstdio>
#include <vector>

using namespace std;

void insertSort(vector<int> &nums)
{
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
        for (int j = i; j > 0 && nums[j] < nums[j-1]; --j) {
            swap(nums[j], nums[j-1]);
        }
    }
}



int main()
{

}