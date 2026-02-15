class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();

        int totalSum = 0;
        for (int x : cardPoints) totalSum += x;

        if (k == n) return totalSum;

        int windowSize = n - k;

        int currentSum = 0;
        for (int i = 0; i < windowSize; i++) {
            currentSum += cardPoints[i];
        }

        int minSum = currentSum;

        for (int i = windowSize; i < n; i++) {
            currentSum += cardPoints[i];
            currentSum -= cardPoints[i - windowSize];
            minSum = min(minSum, currentSum);
        }

        return totalSum - minSum;
    }
};
