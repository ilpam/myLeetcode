class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int result = 0, pop;
        bool nagative = false;
        while (i < s.size() && s[i] == ' ') {
            ++i;
        }
        if (i < s.size()) {
            if (s[i] == '-') {
                nagative = true;
                ++i;
            } else if (s[i] == '+') {
                ++i;
            } 
        }
 
        while (i < s.size() && isdigit(s[i])) {
            pop = (s[i] - '0');
            if (result > INT_MAX/10 || (result == INT_MAX/10 && pop > 7)) {
                return nagative ? INT_MIN : INT_MAX;
            }
            result = result * 10 + pop;
            ++i;
        }
        return nagative ? -result : result;
    }
};