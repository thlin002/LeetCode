#include <vector>

// Traverse the array in a for-loop
// 2 pointers, 1 size counter
// The elements before the 1st pointer are removed of their duplicates
// The second pointer scans from the 1st pointer and stops at the next unique element for each loop
// Shift the all the elements pointed by the 2nd pointer and those after by the distance between 1st and 2nd pointers.
// The size counter is initialize with the size of the array.
// The size of the counter is reduces whenever there is a shift.

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums){
        int size = nums.size();
        for(int ptr1 = 0; ptr1 < size-1; ++ptr1) {
            int ptr2 = ptr1 +1;
            while(ptr2 < size){
                if(nums[ptr2] != nums[ptr1]){
                    break;
                }
                ++ptr2;
            }
            int shift = (ptr2 - ptr1) - 1;
            while(ptr2 < size){
                nums[ptr2-shift] = nums[ptr2];
                ++ptr2;
            }
            size -= shift;
        }
        return size;
    }
};