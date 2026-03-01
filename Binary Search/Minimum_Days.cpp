class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        if ((long long)m * k > b.size()) return -1;
        
        int l = *min_element(b.begin(), b.end());
        int r = *max_element(b.begin(), b.end());
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0, cur = 0;
            
            for (int x : b) {
                cur = (x <= mid) ? cur + 1 : 0;
                if (cur == k) cnt++, cur = 0;
            }
            
            if (cnt >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
