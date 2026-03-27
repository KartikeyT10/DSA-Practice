class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;

        for (char c : word) {
            if (isupper(c)) count++;
        }

        if (count == word.size()) return true;       
        if (count == 0) return true;               
        if (count == 1 && isupper(word[0])) return true; 

        return false;
    }
};
