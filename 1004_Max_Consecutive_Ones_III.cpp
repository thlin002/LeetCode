#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxConsecCnt = 0;
        int consecCnt = 0; // The current size of the sequence of consecutive ones ending at index i.
        int zeroesUsed = 0; // A counter for how many zeroes have been flipped
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1) {
                ++consecCnt;
            } 
            else if(k == 0) { // Implied condition k == 0 && nums[i] == 0. Without this else if clause the program could still work, but this logic is more efficient for the case of k == 0. 
                // If k == 0, then calculate the longest consecutive ones like you normally would, i.e. reset the cnt to 0 when nums[i] == 0.
                consecCnt = 0;
            }
            else { // Implied condition k != 0 && nums[i] == 0.
                if(zeroesUsed < k) {
                    // Flip the zero at index i to 1
                    ++consecCnt;
                    ++zeroesUsed;
                }
                else if(zeroesUsed == k) { // All the chances to flip a zero have been used up.
                    // If the first element of the consecutive ones sequence is a flipped "0", we could restore it to zero, and use the restored flipping option to the zero at index i (the current index). 
                    // When the aforementioned action is done, then the consecCnt stays the same and the zeroesUsed count still equals to k, i.e. no action needed, proceed to the next index (loop).

                    // If the first element of the sequence of consecutive ones is not a flipped "0", meaning a real "1", then we have run out of the zero flipping option.
                    // In this case, we trim off the part of the sequence ending at the first flipped zero in the sequence.
                    // Since the flipped zero that is trimmed off is longer used, we restore this flipped zero and use the restored flipping option to the zero at index i.
                    // This while loop removes all the ones that came before the restored zero, including the restored zero itself. The restored zero was originally counted as a one.
                    while(nums[i-consecCnt] == 1) {
                        --consecCnt;
                    }             
                }
            }
            
            if(consecCnt > maxConsecCnt) {
                maxConsecCnt = consecCnt;
            }
        }

        return maxConsecCnt;
    }
};