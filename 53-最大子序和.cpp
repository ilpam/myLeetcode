class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
        }
        return *max_element(dp.cbegin(), dp.cend());
    }
};