class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (!envelopes.size()) return 0;
        stable_sort(envelopes.begin(), envelopes.end(), 
            [](const vector<int> &a, const vector<int> &b)
                { return (a[0] == b[0] ? a[1] > b[1]: a[0] < b[0]);});
        vector<int> findLIS;
        for(auto v : envelopes) {
            findLIS.push_back(v[1]);
        }
        return getLIS(findLIS);
    }

    int getLIS(const vector<int> &v) {
        int len = v.size();
        vector<int> dp(len, 1);
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (v[i] > v[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return *max_element(dp.cbegin(), dp.cend());
    }
};