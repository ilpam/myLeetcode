
#include <cstdio>
#include <vector>

using namespace std;

void selectSort(vector<int> &nums)
{
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
        int min = i;
        for (int j = i + 1; i < len; ++i) {
            if (nums[j] < nums[min]) min = j;
        }
        swap(nums[min], nums[i]);
    }
}



int main()
{

}