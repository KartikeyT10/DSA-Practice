class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = INT_MIN;

        for (int top = 0; top < rows; top++) {
            vector<int> colSum(cols, 0);

            for (int bottom = top; bottom < rows; bottom++) {

                for (int c = 0; c < cols; c++) {
                    colSum[c] += matrix[bottom][c];
                }

                ans = max(ans, maxSubArrayNoGreaterThanK(colSum, k));
            }
        }
        return ans;
    }

private:
    int maxSubArrayNoGreaterThanK(vector<int>& arr, int k) {

        set<int> prefix;
        prefix.insert(0);

        int currentSum = 0;
        int best = INT_MIN;

        for (int x : arr) {
            currentSum += x;

            int target = currentSum - k;

            auto it = prefix.lower_bound(target);
            if (it != prefix.end()) {
                best = max(best, currentSum - *it);
            }

            prefix.insert(currentSum);
        }
        return best;
    }
};
