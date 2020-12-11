//下面这段代码有问题，只能通过部分测试用例
//针对输入：[3,2,3,1,2,4,5,5,6] 4会输出5，答案是4
// 问题在于大根堆最后一个元素不一定是最小的元素！！！！！！！！！！！！！！！！
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> heap(k+1, 0);
        int lastIdx = 0;
        
        for (int i = 0; i < n; ++i) {
            if (lastIdx < k) {
                ++lastIdx;
                heap[lastIdx] = nums[i];
                swim(heap, lastIdx);
            } else {
                if (nums[i] > heap[lastIdx]) {  // get lager num
                    heap[lastIdx] = nums[i];
                    swim(heap, lastIdx);
                }  
            }
        }
        return heap[k];
    }
private:
    void swim(vector<int> &heap, int k) {
        while (k > 1) {
            if (heap[k] > heap[k/2]) {
                swap(heap[k], heap[k/2]);   
            }
            k = k/2;
        }
    }


};

//下面这个可以全部通过测试，只要将其转换成删除前k-1个即可
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = n-1; i >= 0; --i) {     //这里i的起始可以修改成n/2，跳过所有只有一个结点的堆
            sink(nums, n, i);
        }

        for (int i = 1; i < k; ++i) {
            delMax(nums, n, 1);
        }
        return nums[0];
    }
private:
    inline int left(int x) {
        return 2*x+1;
    }
    inline int right(int x) {
        return 2*x+2;
    }

    void delMax(vector<int> &heap, int n, int k) {
        heap[0] = INT_MIN;
        sink(heap, n, 0);
    }

    // heap root as index 0
    void sink(vector<int> &heap, int n, int k) {
        while (left(k) < n) {
            int maxPos = left(k);
            if (right(k) < n && heap[right(k)] > heap[maxPos]) {
                maxPos = right(k);
            }
            if (heap[k] > heap[maxPos]) break;
            swap(heap[k], heap[maxPos]);
            k = maxPos;
        }
    }

};

//快速选择版的解法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        int pivot_pos;
        int lo = 0, hi = n-1;

        do {
            pivot_pos = partition(nums, lo, hi);
            if (pivot_pos == target) {
                return nums[target];
            } else if (pivot_pos < target) {
                lo = pivot_pos + 1;
            } else {
                hi = pivot_pos -1;
            }
        } while (1);
    }

private:
    int partition(vector<int> &nums, int lo, int hi) {    // [lo, hi]
        int pivot = nums[lo];
        while (hi > lo) {
            while (hi > lo && nums[hi] >= pivot) --hi;
            nums[lo] = nums[hi];
            while (hi > lo && nums[lo] <= pivot) ++lo;
            nums[hi] = nums[lo];
        }
        nums[lo] = pivot;
        return lo;
    }
};