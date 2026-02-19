class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        
        freq[0] = 1; 

        int prefixSum = 0;
        int count = 0;

        for (int x : nums) {
            prefixSum += x;

            int remainder = prefixSum % k;

            if (remainder < 0) remainder += k;

            if (freq.find(remainder) != freq.end()) {
                count += freq[remainder];
            }

            freq[remainder]++;
        }

        return count;
    }
};
