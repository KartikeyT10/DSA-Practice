class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, result = "";

        while (ss >> word) {
            string prefix = "";
            bool found = false;

            for (int i = 1; i <= word.size(); i++) {
                prefix = word.substr(0, i);
                if (st.count(prefix)) {
                    result += prefix + " ";
                    found = true;
                    break;
                }
            }

            if (!found)
                result += word + " ";
        }

        result.pop_back();
        return result;
    }
};
