


class Solution {
public:
    int fib(int N) {
        if (N < 2) return N;
        vector<int> f(N+1, 0);
        f[0] = 0, f[1] = 1;
        for (int i = 2; i <= N; ++i) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[N];
    }
};



class Solution {
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1);
        coinCnt(coins, amount);
        return dp[amount];
    }

    int coinCnt(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (dp[amount]) {
            return dp[amount];
        }

        int sub;
        int minCnt = INT_MAX;
        for (auto coin : coins) {
            
            sub = coinCnt(coins, amount - coin);
            if (sub != -1) {
                minCnt = min(minCnt, sub+1);
            }
        }
        minCnt = (minCnt == INT_MAX) ? -1 : minCnt;
        dp[amount] = minCnt;
        return minCnt; 
    }

};

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