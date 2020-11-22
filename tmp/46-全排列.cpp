//my solution 1
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backTrack(nums, track);
        return result;
    }

private:
    vector<vector<int>> result;
    void backTrack(vector<int> &nums, vector<int> &track) {
        if (track.size() == nums.size()) {
            result.push_back(track);
            return;
        }

        for (auto i : nums) {
            if (findInTrk(track, i)) {
                continue;
            }
            track.push_back(i);
            backTrack(nums, track);
            track.pop_back();
        }
    }

    bool findInTrk(const vector<int> &track, int i) {
        return (std::find(track.cbegin(), track.cend(), i) == track.cend()) ? false : true;
    }
};


//无需多次搜寻
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backTrack(nums, track, 0, nums.size());
        return result;
    }

private:
    vector<vector<int>> result;
    void backTrack(vector<int> &nums, vector<int> &track, int first, int size) {
        if (track.size() == size) {
            result.push_back(track);
            return;
        }

        for (int i = first; i < size; ++i) {
            track.push_back(nums[i]);
            swap(nums[i], nums[first]);
            backTrack(nums, track, first + 1, size);
            swap(nums[i], nums[first]);
            track.pop_back();
        }
    }

};

//leetcode题解，直接去除track
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
