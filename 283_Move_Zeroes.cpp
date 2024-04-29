#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator itNonZero = nums.begin();    // A pointer for the non-zero elements of the array.
        vector<int>::iterator itNum = nums.begin();        // A pointer for iterating the array.
        // A for loop that increments itNum and itNonZero
        for(; itNum != nums.end(); ++itNum, ++itNonZero) {
            // A while loop for skipping the zero elements for iterator "itNonZero"
            // In the following while && condition, "itNonZero != nums.end()" needs to be placed before "*itNonZero == 0", or else an overflow iterator might be used to evaluate "*itNonZero == 0", causing an error.
            while(itNonZero < nums.end() && *itNonZero == 0) {
                ++itNonZero;
            }

            // Assign *itNum the value of *itNonZero to shift forward the non-zero elements
            // If the itNonZero overflowed, then it means that all non-zero elements are shifted, and the rest of the nums array should be filled with zeros.
            if(itNonZero >= nums.end()){
                *itNum = 0;
            } else if (*itNum != *itNonZero){
                *itNum = *itNonZero;
            }
        }
    }
};