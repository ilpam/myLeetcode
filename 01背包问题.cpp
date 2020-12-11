


int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    // vector 全填入 0，base case 已初始化
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int n = 1; n <= N; n++) {
        for (int w = 1; w <= W; w++) {
            if (w - wt[n-1] < 0) { //此处注意，虽然dp数组从1开始，但是wt和val还是从0开始的
                // 当前背包容量装不下，只能选择不装入背包
                dp[n][w] = dp[n - 1][w];
            } else {
                // 注意这一步，有可能不装比装了还要更大！
                dp[n][w] = max(dp[n - 1][w - wt[n-1]] + val[n-1], dp[n - 1][w]);
            }
        }
    }
    return dp[N][W];
}

