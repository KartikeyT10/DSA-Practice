class Solution {
  public:
    int sumOfDigits(int n) {
        if(n==0){
            return 0;
        }
        
        int d= n % 10;
        n= n/10;
        int ans= sumOfDigits(n);
        
        return d+ans;
        
    }
};
