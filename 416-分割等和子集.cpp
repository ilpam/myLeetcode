class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, len = nums.size();
        for (auto num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;
        sum /= 2;
        vector<vector<bool>> dp(len+1, vector<bool>(sum+1, false));
        for (int i = 0; i <= len; ++i) {
            dp[i][0] = true;
        }

        for (int n = 1; n <= len; ++n) {
            for (int w = 1; w <= sum; ++w) {
                if (w - nums[n-1] < 0) {
                    dp[n][w] = dp[n-1][w];
                } else {
                    dp[n][w] = dp[n-1][w-nums[n-1]] || dp[n-1][w];
                }
            }
        }
        return dp[len][sum];
    }
};

