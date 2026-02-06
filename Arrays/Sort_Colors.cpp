#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int low = 0;        // position where next 0 should go
        int mid = 0;        // current index being checked
        int high = n - 1;   // position where next 2 should go

        // process elements until mid crosses high
        while (mid <= high) {

            // if current element is 0
            if (nums[mid] == 0) {
                // swap current element with low index
                swap(nums[low], nums[mid]);

                // move both low and mid forward
                low++;
                mid++;
            }
            // if current element is 1
            else if (nums[mid] == 1) {
                // 1 is already in correct position
                // just move mid forward
                mid++;
            }
            // if current element is 2
            else {
                // swap current element with high index
                swap(nums[mid], nums[high]);

                // move high backward
                // do NOT move mid here because
                // swapped value needs to be checked
                high--;
            }
        }
    }
};
