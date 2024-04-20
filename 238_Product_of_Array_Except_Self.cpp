# include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct;
        vector<int> suffixProduct;
        vector<int> outputProduct;
        int size = nums.size();

        // Calculate the prefix product array and the suffix product array
        // In a prefix product array, ith term pref[i] = arr[0] * ... * arr[i – 1], i in {1, 2, 3,...}, and let pref[0] = 1.
        // In a suffix product array, ith term suff[i] = arr[arrSize-i] * …… * arr[arrSize-1], i in {1, 2, 3,...}, and let suff[0] = 1.
        int tmpPreProd = 1;
        int tmpSufProd = 1;
        prefixProduct.push_back(tmpPreProd);
        suffixProduct.push_back(tmpSufProd);
        for(int i = 0; i < size; ++i) {
            tmpPreProd = nums[i] * tmpPreProd;
            prefixProduct.push_back(tmpPreProd);
            tmpSufProd = nums[size-1-i] * tmpSufProd;
            suffixProduct.push_back(tmpSufProd);
        }

        // Calculate the output product array using the prefix and suffix product array
        for(int i = 0; i < size; ++i) {
            outputProduct.push_back(prefixProduct[i]*suffixProduct[size-1-i]);
        }

        return outputProduct;
    }
};