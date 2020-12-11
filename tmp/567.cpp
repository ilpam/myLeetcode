class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need, window;
        for (auto c : s1) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
        
            if (right - left == s1.size()) {
                if (valid == need.size())
                    return true;
                char c = s2[left];
                left++;
                if (need.count(c)) {
                    if (window[c] == need[c]) valid--;
                    window[c]--;
                }
            }
        }
        return false;
    }
};