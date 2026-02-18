class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        int currentSum = 0;
        int totalCount = 0;

        prefixCount[0] = 1;

        for (int x : nums) {
            currentSum += x;

            if (prefixCount.find(currentSum - k) != prefixCount.end()) {
                totalCount += prefixCount[currentSum - k];
            }

            prefixCount[currentSum]++;
        }

        return totalCount;
    }
};
