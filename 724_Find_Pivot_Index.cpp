#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lSum = 0, rSum = 0;
        // Calculate the right sum when the index is at 0.
        for(int i = 1; i < nums.size(); ++i) {
            rSum += nums[i];
        }

        int p = 0;
        while(lSum != rSum) {
            if(++p == nums.size())
                break;
            // Add the element on the left of the index to the left sum. 
            lSum += nums[p-1];
            // Remove the element that the index points to from the right sum.
            rSum -= nums[p];
        }

        if(p == nums.size())
            return -1;

        return p;
    }
};