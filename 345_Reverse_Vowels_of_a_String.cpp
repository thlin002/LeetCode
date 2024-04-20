#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        stack<char> stk;
        string rv_str;
        for(int i = 0; i < s.size(); ++i) {
            if(isVowel(s[i])) {
                stk.push(s[i]);
            }
        }
        for(int i = 0; i < s.size(); ++i) {
            if(isVowel(s[i])) {
                rv_str.append(1, stk.top());
                stk.pop();
            }
            else {
                rv_str.append(1, s[i]);
            }
        }
        return rv_str;
    }

    bool isVowel(char c) {
        char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i = 0; i < 10; ++i){
            if(c == vowels[i])
                return true;
        }
        return false;
    }
};