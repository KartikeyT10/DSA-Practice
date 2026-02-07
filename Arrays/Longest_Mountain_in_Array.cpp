#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        int longest = 0;  

        int i = 1;        

        while (i < n - 1) {

            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {

                int left = i - 1;
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }

                int right = i + 1;
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                longest = max(longest, right - left + 1);

                i = right + 1;
            } else {
                i++;
            }
        }

        return longest;
    }
};
