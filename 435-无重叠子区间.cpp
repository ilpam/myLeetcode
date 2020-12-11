
// my solution
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (!intervals.size()) return 0;
        stable_sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {return a.back() < b.back();});
        vector<int> x = intervals[0];
        int count = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].front() >= x.back()) {
                x = intervals[i];
                count++;
            }
        }
        count++;
        return intervals.size()-count;
    }
};