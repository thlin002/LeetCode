#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // ref: https://leetcode.com/problems/increasing-triplet-subsequence/solutions/78993/clean-and-short-with-comments-c
        // This algorithm keeps a record of 2 temporary index. tmpMid points to a "value" that is always larger then that of tmpMin.
        // tmpMin will be updated when a smaller value is found.
        // tmpMid will be updated when a value smaller then nums[tmpMid] but larger then nums[tmpMin] is found.
        // At the end of this function, the "index" tmpMin and tmpMid are not guaranteed to maintain the relation that tmpMin < tmpMid.
        int size = nums.size();
        int  tmpMin = INT_MAX, tmpMid = INT_MAX;
        for(int i = 0; i < size; ++i) {
            if(nums[i] <= tmpMin) {
                tmpMin = nums[i];
            } else if (nums[i] <= tmpMid) {
                tmpMid = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};