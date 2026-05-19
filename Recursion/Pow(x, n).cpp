class Solution {
public:
    double myPow(double x, int n) {
        double temp;
        if (n == 1){
            return x;
        }

        temp = pow(x, n/2);
        if (n%2==0){
            return temp*temp;
            
        }
        else{
            return temp*temp*x;

        }
        
    }
};
