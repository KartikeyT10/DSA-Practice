class Solution {
public:
    bool fun(string &s, int low, int high){
        int len = high - low +1;
        if(len == 0 or len == 1){
            return true;
        }
        if(s[low]!= s[high]){
            return false;
        }

        return fun(s, low+1, high-1);

    }
    
    bool isPalindrome(string s) {
        string temp = "";

        for(char ch:s){
            if(isalnum(ch)){
                temp += tolower(ch);
            }
        }
        return fun(temp, 0, temp.length()-1);
       
    }
};
