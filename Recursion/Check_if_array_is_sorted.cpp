class Solution {
  public:
    bool func(int low, int high, vector<int>& arr){
        int len= high-low+1;
        if(len == 0 or len == 1){
            return true;
        }
        
        if (arr[low] > arr[low+1]){
            return false;
        }
        return func(low+1, high, arr);
    }
    
    
    bool isSorted(vector<int>& arr) {
        return func(0, arr.size()-1, arr);
    }
};
