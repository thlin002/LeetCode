#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;

        // Set one pointer to the left and one to the right of the array.
        vector<int>::iterator it_r = height.begin();
        vector<int>::iterator it_l = height.end() - 1;

        // In this loop, we always move the pointer that points to the lower line,
        // because we are finding the maximum area.
        while(it_r < height.end()-1 && it_l > it_r) {
            int width = (it_l - it_r);

            // The height of the area is the same as the lower one of the two.
            int height;
            if(*it_l <= *it_r) {
                height = *it_l;
                --it_l; // Move the left pointer to the right.
            }
            else {
                height = *it_r;
                ++it_r; // Move the right pointer to the left.
            }

            int area = height * width;
            if(area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }
};