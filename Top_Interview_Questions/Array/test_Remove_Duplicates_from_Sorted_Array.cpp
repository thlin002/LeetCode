#include <vector>
#include <iostream>
#include <string>
#include "Remove_Duplicates_from_Sorted_Array.cpp"

std::string intVector_to_string(const std::vector<int>& v, int end){
    std::string tmpstr = "";
    for(int i = 0; i < end; ++i){
        tmpstr += std::to_string(v[i]) + ',';
    }
    return tmpstr;
}

int main() {
    Solution sol;
    std::vector<int> test1 = {1,1,2};
    std::vector<int> test2 = {1,1};
    std::vector<int> test3 = {0,0,1,1,1,2,2,3,3,4};

    int tmpResult = sol.removeDuplicates(test1);
    std::cout << "size: " << tmpResult << std::endl;
    std::cout << "array: " << intVector_to_string(test1,tmpResult) << std::endl;
    tmpResult = sol.removeDuplicates(test2);
    std::cout << "size: " << tmpResult << std::endl;
    std::cout << "array: " << intVector_to_string(test2,tmpResult) << std::endl;
    tmpResult =  sol.removeDuplicates(test3);
    std::cout << "size: " << tmpResult << std::endl;
    std::cout << "array: " << intVector_to_string(test3,tmpResult) << std::endl;
    return 0;
}
