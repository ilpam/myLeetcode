class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need, window;
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        for (int i = 0; i < t.size(); ++i) {
            need[t[i]]++;
        }

        while (right < s.size()) {
            char c = s[right];
            ++right;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (valid == need.size()) {
                if (right - left < len) {
                    len = min(right - left, len);
                    start = left;
                }
                char c = s[left];
                ++left;
                if (need.count(c)) {
                    if (window[c] == need[c]) valid--;
                    window[c]--;
                }
            }

        }
        return len == INT_MAX ? "" : s.substr(start, len);

    }
};