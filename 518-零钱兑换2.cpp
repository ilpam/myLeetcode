

//
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<int>> dp(N+1, vector<int>(amount+1, 0));
        for (int i = 0; i <= N; ++i) {
            dp[i][0] = 1;
        }
        for (int n = 1; n <= N; ++n) {
            for (int w = 1; w <= amount; ++w) {
                if (w - coins[n-1] < 0) {
                    dp[n][w] = dp[n-1][w];
                } else {
                    dp[n][w] = dp[n][w-coins[n-1]] + dp[n-1][w];    //注意这里是dp[n][w-coins[n-1]]，不是dp[n-1][w-coins[n-1]]，很重要
                }
            }
        }
        return dp[N][amount];
    }
};

//这道题一维的解法只能按照下面这个循环来，不可交换内外循环，为什么？因为一旦交换了内外循环，子问题划分就是错的！！！
/**
 *  此题目中的dp[w]的定义并非最终用n个凑出w的硬币总数，实际上，由于dp[w]利用他自身一直在变化，所以dp[w]是带状态n的，
 * 实际上它应该是dp[n][w]，也就是二维解法的状态，所以它和二维是一样的解释，只不过最终dp[N][amount]正好等于dp[amount]而已；
 * 如果交换了内外循环，因为dp[w]仍然利用自己进行变化，所以dp[w]仍然是带状态的，它是dp[n][w]，可是，根据内外循环的语义，dp[w]只会被计算一次，
 * 那么在后面使用 dp[w] += dp[w-coins[n-1]]的时候，实际上你是用了dp[n][w] = dp[n][w-coins[n-1]] + dp[n][w]，而实际上正确的状态转移应该是
 * dp[n][w] = dp[n][w-coins[n-1]] + dp[n-1][w]
 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int n = 1; n <= N; ++n) {
            for (int w = 1; w <= amount; ++w) {
                if (w - coins[n-1] >= 0) {
                    dp[w] += dp[w-coins[n-1]];    //在不使用第n个硬币的基础上，加上使用第n个硬币凑出w的办法
                }
            }
        }
        return dp[amount];
    }
};

