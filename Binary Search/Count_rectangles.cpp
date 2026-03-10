class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> height(101);

        for (auto &r : rectangles) {
            height[r[1]].push_back(r[0]);
        }

        for (int i = 0; i <= 100; i++) {
            sort(height[i].begin(), height[i].end());
        }

        vector<int> ans;

        for (auto &p : points) {
            int x = p[0], y = p[1];
            int count = 0;

            for (int h = y; h <= 100; h++) {
                auto &vec = height[h];
                if (vec.empty()) continue;

                auto it = lower_bound(vec.begin(), vec.end(), x);
                count += vec.end() - it;
            }

            ans.push_back(count);
        }

        return ans;
    }
};
