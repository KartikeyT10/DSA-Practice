class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> firstIndex;

        int prefixSum = 0;
        int maxLength = 0;

        firstIndex[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) prefixSum -= 1;
            else prefixSum += 1;

            if (firstIndex.count(prefixSum)) {
                int length = i - firstIndex[prefixSum];
                maxLength = max(maxLength, length);
            } 
            else {
                firstIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};
