/*
*   方法一：暴力穷举；
*   方法二：对于第一个x，只需要快速查找到是否存在target-x即可，这样的话我们希望target-x做key，在hash table中查找它的index作为value,
*           你不能先把所有的x作为key加入hash table中，因为有可能target-x==x
*
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};