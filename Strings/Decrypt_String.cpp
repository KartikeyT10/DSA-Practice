class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        
        for (int i = 0; i < s.length(); ) {

            if (i + 2 < s.length() && s[i + 2] == '#') {
                int num = stoi(s.substr(i, 2)); 
                result += char('a' + num - 1);ter
                i += 3;
            } else {
                int num = s[i] - '0';
                result += char('a' + num - 1);
                i += 1;
            }
        }
        
        return result;
    }
};
