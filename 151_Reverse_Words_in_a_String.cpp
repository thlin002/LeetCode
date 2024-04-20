#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string revStr = "";
        vector<string> revStrings = splitString(s, ' ');
        
        for(int i = revStrings.size()-1; i >= 0; --i){
            revStr.append(revStrings[i]);
            if(i != 0){
                revStr.append(" ");
            }
        }
        
        return revStr; 
    }

    /**
    * @brief  Split the string into strings by the separator.
    * 
    * Split the string by the separator.
    * Consecutive delimiters are grouped together, so this method will not delimit empty strings.
    * For example, splitString("1  2", ' ') returns vector<string> {"1", "2"}.
    * 
    * @param  s:  string to be split
    * @param  seperator:  a character used to split the string
    * 
    * @return  a vector<string> of the seperated strings
    */
    vector<string> splitString(string s, char separator) {
        vector<string> splitArray;
        int b = 0, e = 0; // beginning index and ending index
        int size = s.size();

        while(1) { 
            int ind;
            ind = s.find_first_not_of(separator, e); // find the first char that is not equal to the seperator after position e
            b = ind == -1 ? size : ind; // if cannot find matching char, then set the index equal to the size of the string.
            ind = s.find(separator, b); // find the first char that is equal to the seperator after position b
            e = ind == -1 ? size : ind; // if cannot find matching char, then set the index equal to the size of the string.
            if(b == size) 
                break; //if the beginning index reached the end, break.
            else
                splitArray.push_back(s.substr(b, e-b)); // else append the separated substring into the vector
        }
        
        return splitArray;
    }
};