class Solution {
public:
    bool canReach(vector<int>& dist, double hour, int speed) {
        double time = 0.0;
        int n = dist.size();
        
        for (int i = 0; i < n; i++) {
            double travel = (double)dist[i] / speed;
            
            if (i < n - 1) {
                time = ceil(time + travel);
            } else {
                time += travel;
            }
            
            if (time > hour) return false;
        }
        
        return time <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 10000000, ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canReach(dist, hour, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
