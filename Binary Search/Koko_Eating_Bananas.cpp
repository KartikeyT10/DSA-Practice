class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        long long left = 1;
        long long right = 0;

        for (int p : piles) {
            right = max(right, (long long)p);
        }

        int ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            long long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid;
            }

            if (hours <= h) {
                ans = mid;
                right = mid - 1; 
            } 
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
