#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int maxAlt = 0;
        for(int i = 0; i < gain.size(); ++i) {
            alt += gain[i];
            if(alt > maxAlt) {
                maxAlt = alt;
            }
        }
        return maxAlt;
    }
};