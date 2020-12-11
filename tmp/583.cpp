class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1,0));

        for (int i = 0; i <= s1; i++) {
            for (int j = 0; j <= s2; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                }
            }
        }

        for (int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[s1][s2];
    }
};


//下面的解答是编辑距离的解答，只多了一个转移方程
class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1,0));

        for (int i = 0; i <= s1; i++) {
            for (int j = 0; j <= s2; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                }
            }
        }

        for (int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = minOfthree(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[s1][s2];
    }

    int minOfthree(int a, int b, int c) {
        int min = ((a > b) ? b : a);
        return min > c ? c : min;
    }
};