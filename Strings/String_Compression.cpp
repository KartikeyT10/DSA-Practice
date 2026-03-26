class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;  
        int k = 0;  
        
        while (i < n) {
            int j = i;

            while (j < n && chars[j] == chars[i]) {
                j++;
            }

            chars[k++] = chars[i];
            
            int count = j - i;

            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[k++] = c;
                }
            }

            i = j;
        }
        
        return k;
    }
};
