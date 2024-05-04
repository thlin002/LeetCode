#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // Sort the nums array in ascending order.
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;
        int count = 0;
        while(left < right) {
            if(nums[left] + nums[right] == k) {
                // Since both numbers at the left and right indices are used, move them both.
                ++left;
                --right;
                ++count;
            }
            else if (nums[left] + nums[right] < k) {
                // Shift the left index one step to the right to increase the sum.
                ++left;
            } else {
                // Shift the right index one step to the left to decrease the sum.
                --right;
            }
        }
        return count;
    }
};