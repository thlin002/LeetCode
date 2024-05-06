#include <string>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        double winCnt = 0;
        double winMaxCnt = 0;
        // Calculate the vowel count in the window at the starting position.
        for(int i = 0; i < k && i < s.size(); ++i) {
            // If s[i] is a vowel, then increment winCnt.
            if(vowels.find(s[i]) != -1)
                ++winCnt;
        }
        winMaxCnt = winCnt;

        for(int i = 0; i < s.size()-k; ++i) {
            // As the window moves forward one step, 
            // if the previous first element is a vowel, then substract it from the window count,
            if(vowels.find(s[i]) != -1)
                --winCnt;
            // and if the next element is a vowel, then add it to the window count.
            if(vowels.find(s[i+k]) != -1)
                ++winCnt;
            
            if(winCnt > winMaxCnt) {
                winMaxCnt = winCnt;
            }
        }
        return winMaxCnt;
    }
};