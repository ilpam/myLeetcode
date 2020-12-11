//my solution, 区间问题小变种
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (!points.size()) return 0;
        stable_sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {return a.back() < b.back();});
        vector<int> x = points[0];
        int count = 0;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].front() > x.back()) {
                x = points[i];
                count++;
            }
        }
        count++;
        return count;
    }
};