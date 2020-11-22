
// 有序向量的去重
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int length = 1;
        bool new_value = true;
        if (nums.size() == 0) return 0;
        for (int i = 0, j = 1; j < n;) {
            while (nums[j] == nums[i]) {
                ++j;
                if (j >= n) {
                    new_value = false;   // to end and no new value
                    break;
                } 
            }
            if (new_value) {
                nums[++i] = nums[j];  
                length++;   
            }
        }
        return length;
    }
};