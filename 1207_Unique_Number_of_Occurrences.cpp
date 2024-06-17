#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Count the occurences of the numbers in the array.
        unordered_map<int, int> map;
        for(vector<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter) {
            // If the key is not found in the map, insert a new element with that key and set the value to 1 (representing the first occurrence).
            if(map.find(*iter) == map.end()) {
                map[*iter] = 1;
            }
            // If the key is found in the map, increment the mapping value of the key.
            else {
                ++map[*iter];
            }
        }
        // Check if the number of occurrences of each value in the array is unique.
        unordered_map<int, int> cntMap;
        // Notes: unordered_map::iterator is a forward iterator. It does not support the greater-than/less-than operators.
        for(unordered_map<int, int>::iterator iter = map.begin(); iter != map.end(); ++iter) {
            if(cntMap.find(iter->second) == cntMap.end()) {
                cntMap[iter->second] = 1;
            }
            // If the number of occurrences of each value in the array is not unique, return false.
            else if(++cntMap[iter->second] == 2){
                return false;
            }
        }
        return true;
    }
};