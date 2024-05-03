#include <string>
using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t) {
            string::iterator it_s = s.begin();
            string::iterator it_t = t.begin();
            
            // If s an empty string, then return true
            if(s == "")
                return true;
            
            // Traverse string t using pointer it_t, 
            // if it_t is pointing to a char that is equal to the char it_s is pointing to, then move it_s to the next char.
            // Return true if it_s reached the end of the string s.
            for(; it_t != t.end(); ++it_t) {
                if(*it_t == *it_s)
                    ++it_s;

                if(it_s == s.end())
                    return true;
            }

            return false;
        }
};