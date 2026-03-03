#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int books(vector<int> &A, int B) {
        int n = A.size();
        if (B > n) return -1;  // More students than books not possible

        long long low = *max_element(A.begin(), A.end());
        long long high = accumulate(A.begin(), A.end(), 0LL);

        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canAllocate(A, B, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

private:
    bool canAllocate(vector<int> &A, int B, long long maxPages) {
        long long sum = 0;
        int students = 1;

        for (int pages : A) {
            if (sum + pages <= maxPages) {
                sum += pages;
            } else {
                students++;
                sum = pages;
                if (students > B) return false;
            }
        }
        return true;
    }
};
