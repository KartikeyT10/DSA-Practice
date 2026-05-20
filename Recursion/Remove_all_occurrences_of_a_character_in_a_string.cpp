class Solution {
public:

    string fun(string &s, int n, int i, char c){

        if(i == n){
            return "";
        }

        string ans = fun(s, n, i + 1, c);

        if(s[i] == c){
            return ans;
        }

        return s[i] + ans;
    }

    void removeCharacter(string &s, char c) {

        s = fun(s, s.length(), 0, c);
    }
};
