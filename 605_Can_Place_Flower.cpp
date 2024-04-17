class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int bedsize = flowerbed.size();
        
        // the flower bed has a size of 1
        for(int i = 0; i < bedsize; ++i){
            if(flowerbed[i] == 0){
                int leftempty = i == 0 || flowerbed[i-1] == 0;
                int rightempty = i == bedsize-1 || flowerbed[i+1] == 0;

                if(leftempty && rightempty){
                    flowerbed[i] = 1;
                    ++cnt;
                }
            }
        }

        return cnt >= n;
    }
};