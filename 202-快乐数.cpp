class Solution {
public:
    bool isHappy(int n) {
        int fast = caculate(n), slow = n;
        if (n == 1) return true;
        while (fast != slow) {
            if (fast == 1) {
                return true;
            }
            fast = caculate(caculate(fast));
            slow = caculate(slow);
        }
        return false;
    }

private:

    int caculate(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
/*
    int caculate(int x) {
        int result = 0;
        int mod;
        while (x) {
            mod = x % 10;
            x /= 10;
            result = result + mod * mod;
        }
        result = result + mod * mod;
        return result;
    }*/
};