/*
 * 假如先固定左边，很显然，对于右边相同高度，肯定是越远越好：
 *      如果右边从左往右移动，你无法知道比较左短的是否面积更大；如果从右往左移动，就必然知道比前一个更短的不用计算，可以节省一些计算；
 * 以上只是单向的，假如我们只做单向的，之后还需要一步步改变左边，对每一条左边都重复上面的操作，其实是不必要的
 *
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return -1;
        int i = 0, j = height.size() - 1, res = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            if(height[i] < height[j]) ++i;
            else --j;
        }
        return res;
    }
};