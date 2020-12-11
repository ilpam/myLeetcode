

// my solution，递推的动态规划，最后一个用例超时
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1) return 0;
        if (len == 2) return 1;
        vector<int> dp(len, len);
        dp[len-2] = 1;
        for (int i = len-3; i >= 0; --i) {
            for (int j = 0; j <= nums[i]; ++j)
            if (i+j > len-2) {
                dp[i] = 1;
                continue;
            } else {
                dp[i] = min(dp[i], dp[i+j]+1);
            }
        }
        return dp[0];
    }
};