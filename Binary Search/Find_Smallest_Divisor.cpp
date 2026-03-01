class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long sum = 0;
            
            for (int x : nums) {
                sum += (x + mid - 1) / mid;
            }
            
            if (sum <= threshold) hi = mid; 
            else lo = mid + 1;
        }
        
        return lo;
    }
};
