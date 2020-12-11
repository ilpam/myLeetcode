
//递归解法
class Solution {
public:
    bool isMatch(string s, string p) {
        
        if (!p.size()) return !s.size();
        bool match = (s.size() && (s[0] == p[0] || p[0] == '.'));
        if (p.size() > 1 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (match && isMatch(s.substr(1), p));
        } else {
            return match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

