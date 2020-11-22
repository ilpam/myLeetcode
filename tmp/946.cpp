


//下面这个解法是我的思路，有问题，未完成
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int popedIdx = 0, i = 0;
        while (pushed[i] != popped[popedIdx]) {
            stk.push_back(pushed[i]);
            ++i;
        }

        popedIdx ++;
        while (popedIdx < popped.size()) {
            /*
            if (popped[popedIdx] == stk.[stk.size()-1]) {
                popedIdx++;

                i++;
                while (pushed[i] != popped[popedIdx]) {
                    stk.push_back(pushed[i]);
                    ++i;
                }
            } else */
            
            if (findInStk(popped[popedIdx])) {
                return false;
            } else if (popped[popedIdx] == stk[stk.size()-1]) {
                popedIdx++;
            } else {
                // popped[popedIdx] has not been in stk
                i++;
                while (pushed[i] != popped[popedIdx]) {
                    stk.push_back(pushed[i]);
                    ++i;
                }
                popedIdx++;
            }
        }
        
        return true;
    }


private:
    vector<int> stk;
    bool findInStk(int x) {
        for (int i = 0; i < stk.size()-1; ++i) {
            if (stk[i] == x) {
                return true;
            }
        }
        return false;
    }
};


//以下代码有越界问题
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            stk.push(pushed[i]);
            while (stk.top() ==  popped[j]) {
                stk.pop();
                ++j;
            }
        }
        if (stk.size()) return false;
        else return true;
    }
};

//完整代码
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            stk.push(pushed[i]);
            while (stk.size() && (stk.top() ==  popped[j])) {   
            //或者 while ((stk.size() && (j < popped.size())) && (stk.top() ==  popped[j]))
                stk.pop();
                ++j;
            }
        }
        if (stk.size()) return false;
        else return true;
    }
};

