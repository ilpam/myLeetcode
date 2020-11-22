
#include <cstdio>
#include <string>
#include <unordered_set>
/*
*   滑动窗口
*
*
*/


using std::string;
using std::unordered_set;

class Solution {
public:
    int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s) {
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

int main()
{
    Solution s;
    printf("%d\n", s.lengthOfLongestSubstring("tmmzuxt"));
    return 0;
}