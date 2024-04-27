#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    Solution(): cnt(0), lastChar('\0') {

    }

    int compress(vector<char>& chars) {
        int size = chars.size();
        string str = "";
        for(int i = 0; i < size; ++i) {
            int currentCnt = counter(chars[i]);
            char nextChar = i+1 > size-1 ? '/0': chars[i+1]; // Set nextChar to '\0', if i+1 exceeds the valid range.

            if(currentCnt == 1) {
                // For the first occurrence of a character, append the character itself to the result string.
                str += chars[i];
            } else if(chars[i] != nextChar) {
                // Else if the next character is different, add the count of the current character repetitions to the result string.
                str += to_string(currentCnt);
            }
        }
        
        // Copy the string to the vector of char "chars" as requested by the problem description.
        chars.clear();
        int newSize = str.size();
        for(int i = 0; i < newSize; ++i) {
            chars.push_back(str[i]);
        }

        return newSize;
    }

private:
    int counter(char c) {
        // Returns the number of repetitions of the current character.
        if(lastChar == c) {
            // If the current character repeats the previous character, increase its count.
            ++cnt;
            return cnt;
        } else {
            // When we encounter a new character, 
            // update lastChar to the current character and restart the count by setting cnt to 1.
            lastChar = c;
            cnt = 1;
            return cnt;
        }
    }

    int cnt;
    char lastChar;
};