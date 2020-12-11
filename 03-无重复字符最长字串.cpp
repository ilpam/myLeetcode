
//第一次提交
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int maxLen = 1, curLen = 0;
        int start = 0, end = 0;
        if (!s.size()) return 0;
        while (end != s.size()) {
            while (!set.count(s[end])) {
                set.insert(s[end]);
                end++;
                if (end == s.size()) break;
            }
            maxLen = maxLen > (end - start) ? maxLen : (end - start);
            while (s[start] != s[end]) {
                set.erase(s[start]);
                start++;
            }
            set.erase(s[start]);
            start++;
        }
        maxLen = maxLen > (end - start) ? maxLen : (end - start);
        return maxLen;
    }
};

//第二次提交
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;

        int left = 0, right = 0;
        int maxLen = 0;
        while (right < s.size()) {
            char c = s[right++];
            window[c]++;
            while (window[c] > 1) {
                char d = s[left++];
                window[d]--;
            }
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};