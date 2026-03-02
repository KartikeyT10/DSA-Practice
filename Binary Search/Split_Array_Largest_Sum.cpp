class Solution {
public:
    bool canSplit(vector<int>& nums, int m, long long maxAllowed) {
        long long currentSum = 0;
        int parts = 1;
        
        for (long long x : nums) {
            if (currentSum + x <= maxAllowed) {
                currentSum += x;
            } else {
                parts++;
                currentSum = x;
                if (parts > m) return false;
            }
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;

        for (long long x : nums) {
            left = max(left, x); 
            right += x;        
        }
        
        long long ans = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (canSplit(nums, m, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return (int)ans;
    }
};
