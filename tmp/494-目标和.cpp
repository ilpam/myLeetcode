
//我的解法，会超出时间限制，但是没有问题看起来, 你可以对此算法做备忘录优化，但是要修改一下helper的结构
class Solution {
public:
    int result = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        helper(nums, 0, 0, S);
        return result;
    }

    void helper(vector<int> &nums, int i, int curr, int S) {
        if (i == nums.size()) {
            if (curr == S) result++;
            return;
        }
        helper(nums, i+1, curr + nums[i], S);
        helper(nums, i+1, curr - nums[i], S);
    }
};

//我的最终提交，一定要注意，数组的大小
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int N = nums.size();
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        if (abs(S) > abs(sum)) return 0;
        int len = 2*sum+1;
        vector<vector<int>> dp(N + 1, vector<int>(len, 0));

        if (nums[0] == 0) {
            dp[1][sum] = 2;
        } else {
            dp[1][sum + nums[0]] = 1;
            dp[1][sum - nums[0]] = 1;
        }

        for (int n = 2; n <= N; n++) {
            for (int w = 0; w < len; w++) {
                int l = (w - nums[n-1] >= 0) ? dp[n-1][w-nums[n-1]] : 0; 
                int r = (w + nums[n-1] < len) ? dp[n-1][w+nums[n-1]] : 0;
                dp[n][w] = l+r;
                
            }
        }
        return dp[N][sum+S];
    }
};