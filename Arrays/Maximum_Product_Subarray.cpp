class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        long long maxProd = nums[0];
        long long minProd = nums[0];

        long long ans = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }

            maxProd = max((long long)nums[i], maxProd * nums[i]);
            minProd = min((long long)nums[i], minProd * nums[i]);

            ans = max(ans, maxProd);
        }

        return (int)ans;
    }
};
