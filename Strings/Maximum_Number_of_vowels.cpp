#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, ans = 0;

        for (int i = 0; i < k; i++) {
            if (string("aeiou").find(s[i]) != string::npos)
                count++;
        }

        ans = count;

        for (int i = k; i < s.size(); i++) {
            if (string("aeiou").find(s[i]) != string::npos)
                count++;

            if (string("aeiou").find(s[i - k]) != string::npos)
                count--;

            ans = max(ans, count);

            if (ans == k) return k;
        }

        return ans;
    }
};
