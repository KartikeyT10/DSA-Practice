class Solution {
public:
    
    int findPeak(MountainArray &mountainArr, int n) {
        int l = 0, r = n - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        
        return l;
    }
    
    int binarySearchAsc(MountainArray &arr, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = arr.get(mid);
            
            if (val == target) return mid;
            else if (val < target) l = mid + 1;
            else r = mid - 1;
        }
        
        return -1;
    }
    
    int binarySearchDesc(MountainArray &arr, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = arr.get(mid);
            
            if (val == target) return mid;
            else if (val > target) l = mid + 1;
            else r = mid - 1;
        }
        
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int peak = findPeak(mountainArr, n);
        
        int left = binarySearchAsc(mountainArr, 0, peak, target);
        if (left != -1) return left;
        
        return binarySearchDesc(mountainArr, peak + 1, n - 1, target);
    }
};
