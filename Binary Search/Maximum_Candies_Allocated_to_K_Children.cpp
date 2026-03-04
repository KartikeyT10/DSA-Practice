class Solution {
public:
    long long canServe(vector<int>& candies, long long x) {
        long long count = 0;
        for (int c : candies) {
            count += c / x;
        }
        return count;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1;
        long long right = *max_element(candies.begin(), candies.end());
        long long ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (canServe(candies, mid) >= k) {
                ans = mid;
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
