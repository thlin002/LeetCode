#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
            // std::unordered_set is an associative container that uses hashing for efficient insertion, search, and removal of elements.
            // -> Search, insertion, and removal have average O(1) time complexity.
            // std::unordered_set is used here for its fast element removal.
            unordered_set<int> set1(nums1.begin(), nums1.end());
            unordered_set<int> set2(nums2.begin(), nums2.end());
            for(vector<int>::iterator iter = nums2.begin(); iter < nums2.end(); ++iter) {
                if(set1.find(*iter) != set1.end()) {
                    set1.erase(*iter);
                    set2.erase(*iter);
                };
            }
            vector<vector<int>> results;
            results.push_back(*(new vector<int>(set1.begin(), set1.end())));
            results.push_back(*(new vector<int>(set2.begin(), set2.end())));
            return results;
        }
};