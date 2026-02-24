class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = num;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long prod = mid * mid;

            if (prod == num) {
                return true;
            }
            else if (prod < num) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};
