#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {   
        double winSum;
        double winMaxSum;
        // Calculate the sum of the elements in the window at the starting position.
        for(int i = 0; i < k && i < nums.size(); ++i) {
            winSum += (double)nums[i];
        }
        winMaxSum = winSum;

        for(int i = 0; i < nums.size()-k; ++i) {
            // As the window moves forward one step, the previous first element is removed from the window sum, and the next element is added.
            winSum -= (double)nums[i];
            winSum += (double)nums[i+k];
            if(winSum > winMaxSum) {
                winMaxSum = winSum;
            }
        }
        return winMaxSum / (double)k;
    }
};