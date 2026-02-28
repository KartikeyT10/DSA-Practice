class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {

        long long left = 0;
        long long right = 0;

        for (int w : weights) {
            left = max(left, (long long)w);
            right += w;
        }

        int ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            int days = 1;
            long long current = 0;

            for (int w : weights) {
                if (current + w <= mid) {
                    current += w;
                } else {
                    days++;
                    current = w;
                }
            }

            if (days <= D) {
                ans = (int)mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
