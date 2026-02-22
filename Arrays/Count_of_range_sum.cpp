class Solution {
public:
    long long countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeCount(prefix, 0, n + 1, lower, upper);
    }

private:

    long long mergeCount(vector<long long>& prefix, int left, int right, long long lower, long long upper) {
        if (right - left <= 1) return 0;

        int mid = (left + right) / 2;
        long long count = 0;

        count += mergeCount(prefix, left, mid, lower, upper);
        count += mergeCount(prefix, mid, right, lower, upper);

        int l = mid, r = mid;
        for (int i = left; i < mid; i++) {
            while (l < right && prefix[l] - prefix[i] < lower) l++;
            while (r < right && prefix[r] - prefix[i] <= upper) r++;
            count += (r - l);
        }

        vector<long long> temp;
        int i = left, j = mid;
        while (i < mid && j < right) {
            if (prefix[i] <= prefix[j]) temp.push_back(prefix[i++]);
            else temp.push_back(prefix[j++]);
        }
        while (i < mid) temp.push_back(prefix[i++]);
        while (j < right) temp.push_back(prefix[j++]);

        for (int k = left; k < right; k++) {
            prefix[k] = temp[k - left];
        }

        return count;
    }
};
