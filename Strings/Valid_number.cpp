class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;

        while (i < n && s[i] == ' ') i++;
        while (n > i && s[n - 1] == ' ') n--;

        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;

        for (int j = i; j < n; j++) {
            char c = s[j];

            if (isdigit(c)) {
                seenDigit = true;
            }
            else if (c == '+' || c == '-') {
                if (j > i && s[j - 1] != 'e' && s[j - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                if (seenDot || seenExp)
                    return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (seenExp || !seenDigit)
                    return false;
                seenExp = true;
                seenDigit = false;
            }
            else {
                return false;
            }
        }

        return seenDigit;
    }
};
