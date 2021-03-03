class Solution {
public:
    int cal(int n)
    {
        int ret = 0;
        while (n) {
            int p = n % 10;
            ret += p * p;
            n /= 10;
        }

        return ret;
    }

    bool isHappy(int n)
    {
        if (n == 1)
            return true;

        int slow = cal(n);
        int fast = cal(cal(n));

        while (fast != slow) {
            slow = cal(slow);
            fast = cal(cal(fast));
        }

        if (slow == 1)
            return true;
        return false;
    }
};