class Solution {
//下面这个提交是有问题的，先不用理
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> &dp(amount+1, 0);
        dp[0] = 0;
        for (auto coin : coins) {
            dp[coin] = 1;
        }

        for (int i = 1; i <= amount; ++i) {
            dp[i] = INT_MAX;
            for (auto coin : coins) {
                if (i - coin < 0) {
                    continue;
                } else {
                    dp[i] = min(dp[i-coin] + 1, dp[i]);
                }
            }
            dp[i] = (dp[i] == INT_MAX ? 0 : dp[i]);
        }
        return dp[amount];
    }
};


//第一次提交，从小递推
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); ++i) {
            for (auto c : coins) {
                if (i < c) continue;
                dp[i] = min(dp[i - c]+1, dp[i]);
            }        
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};


//记忆化递归
class Solution {
    vector<int>count;
    int dp(vector<int>& coins, int rem) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (count[rem] != 0) return count[rem];
        int Min = INT_MAX;
        for (int coin:coins) {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < Min) {
                Min = res + 1;
            }
        }
        count[rem] = Min == INT_MAX ? -1 : Min;
        return count[rem];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        count.resize(amount+1);
        return dp(coins, amount);
    }
};
