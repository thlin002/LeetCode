#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // For 2 strings to be considered close strings, they must need the following criteria:
        // 1. Both strings contain the same set of characters.
        // 2. Both strings have identical character frequency distributions.
        unordered_map<char, int> charFreqMap1;
        unordered_map<int, int> freqCountMap1;
        unordered_map<char, int> charFreqMap2;
        unordered_map<int, int> freqCountMap2;

        charFreqAndDist(word1, charFreqMap1, freqCountMap1);
        charFreqAndDist(word2, charFreqMap2, freqCountMap2);

        // Determine if the two strings have identical character frequency distributions.
        if(freqCountMap1 != freqCountMap2)
        {
            return false;
        }

        // Determine if the two strings contain the same set of characters.
        for(auto& charFreqPair : charFreqMap1)
        {
            if(charFreqMap2.find(charFreqPair.first) == charFreqMap2.end())
            {
                return false;
            }
        }

        return true;
    }

private:
    void charFreqAndDist(const string& str, unordered_map<char, int>& charFreqMap, unordered_map<int, int>& freqCountMap) {
        // Calculate the character frequencies.
        for(auto& character : str)
        {
            if(charFreqMap.find(character) == charFreqMap.end())
            {
                charFreqMap[character] = 1;
            }
            else
            {
                charFreqMap[character]++;
            }
        }

        // Calculate the frequency distribution.
        for(auto& charFreqPair : charFreqMap)
        {
            if(freqCountMap.find(charFreqPair.second) == freqCountMap.end())
            {
                freqCountMap[charFreqPair.second] = 1;
            }
            else
            {
                freqCountMap[charFreqPair.second]++;
            }
        }
    }
};