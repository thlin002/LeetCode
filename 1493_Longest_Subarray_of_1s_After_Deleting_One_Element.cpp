#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxConsecCnt = 0;
        int consecCnt = 0; // The number of 1's contained on the current sliding window.
        vector<int>::iterator startIt= nums.begin(); // Points to the start of the sliding window.
        vector<int>::iterator endIt = nums.end(); // Points to the end of the sliding window.
        bool zeroExists = 0;

        // In the for loop below, maintain a sliding window where there is at most one zero on it.
        for(vector<int>::iterator it = nums.begin(); it < nums.end(); ++it) {
            if(*it == 1) { // Expand the window to include the 1's.
                ++consecCnt;
                ++endIt;
            }
            else { 
                if(zeroExists == 0) { // If no zero exists on the current window, then expand the window to include this zero.
                    zeroExists = 1;
                    ++endIt;
                }
                else { // Since the array can only contain one zero, shrink the window by moving startIt to the element following the preceding zero.
                    //  Move startIt pass all the 1's before the preceding zero.
                    while(*startIt == 1 && startIt < nums.end()) {
                        --consecCnt;
                        ++startIt;
                    }
                    // Move startIt pass the preceding zero.
                    ++startIt;
                }
            }
            
            if(consecCnt > maxConsecCnt) {
                maxConsecCnt = consecCnt;
            }
        }
        
        if(zeroExists == 0) { // If no zero exists in the whole nums array, then a '1' must be removed.
            --maxConsecCnt;
        }

        return maxConsecCnt;
    }
};