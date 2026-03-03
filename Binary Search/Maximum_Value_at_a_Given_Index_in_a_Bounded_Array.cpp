class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long left = 1, right = maxSum;

        while (left < right) {
            long long mid = (left + right + 1) / 2;

            if (isValid(n, index, maxSum, mid))
                left = mid;
            else
                right = mid - 1;
        }

        return left;
    }

private:
    bool isValid(int n, int index, int maxSum, long long value) {
        long long sum = value;

        long long leftCount = index;
        if (value > leftCount) {
            long long high = value - 1;
            long long low = value - leftCount;
            sum += (high + low) * leftCount / 2;
        } else {
            long long high = value - 1;
            sum += (high + 1) * high / 2;
            sum += leftCount - high;
        }

        long long rightCount = n - index - 1;
        if (value > rightCount) {
            long long high = value - 1;
            long long low = value - rightCount;
            sum += (high + low) * rightCount / 2;
        } else {
            long long high = value - 1;
            sum += (high + 1) * high / 2;
            sum += rightCount - high;
        }

        return sum <= maxSum;
    }
};
