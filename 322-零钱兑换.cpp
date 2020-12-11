
//这道题的原始解答，相当于把最后一个答案交换了内外循环，也是对的，为什么？
/**
 * 首先，如果不管内层循环，dp[i]的定义就是用所有硬币凑出i的最少硬币数
 * 然后，我们深入内循环，为了求得dp[i]，有多种方式可以凑出i，我们划分成，最后一次刚好用了c0，最后一次刚好用了c1....等coins.size()种情况，
 * 从中挑出最少硬币的一种就可以了
 * 当然，即使最后一次用了ci，前面的凑出方案中也可能用到了ci！！！所以这是一个排列，和跳楼梯问题一摸一样了，相当于跳到特定梯级的最少步数
 * 
 */ 
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

//背包问题，把这个压缩了就变成一维了，使用第n个硬币与不使用第n个硬币凑出m
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        vector<vector<int>> dp(N+1, vector<int>(amount+1, amount+1));
        for (int i = 0; i <= N; ++i) {
            dp[i][0] = 0;
        }
        for (int n = 1; n <= N; ++n) {
            for (int m = 1; m <= amount; ++m) {
                if (m-coins[n-1] < 0) {
                    dp[n][m] = dp[n-1][m];
                } else {
                    dp[n][m] = min(dp[n][m-coins[n-1]]+1, dp[n-1][m]);
                }
            }
        }
        return dp[N][amount] == amount+1 ? -1: dp[N][amount];
    }
};

//压缩后，本质上和二维完全一样
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto c : coins) {
            for (int i = 0; i < dp.size(); ++i) {
                if (i < c) continue;
                dp[i] = min(dp[i - c]+1, dp[i]);
            }        
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};