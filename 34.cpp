class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) return {-1,-1};
        int left = leftBound(nums, target);
        if (left == -1) return {-1,-1};
        int right = rightBound(nums, target);
        return {left,right};
    }

private:
    int leftBound(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size();
        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                hi = mid;
            } else if (nums[mid] > target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (lo < nums.size() && nums[lo] == target) return lo;
        return -1; 
    }

    int rightBound(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size();
        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (lo > 0 && nums[lo-1] == target) return lo-1;
        return -1; 
    }
};