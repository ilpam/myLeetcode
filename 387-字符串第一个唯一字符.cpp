/*
*   建立一个char到int的映射，用来记录字符串中每个字符出现的数目，然后再遍历一次key，检查出value为1的那个字符   
*
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, int> count;
        
        for (auto i = 0; i < s.size(); i++) {           
            if (count.find(s[i]) == count.end()) {
                count[s[i]] = 1;
            } else {
                count[s[i]] += 1;
            }
        }

        for (auto i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) return i;
        }

        
        return -1;
    }
};;