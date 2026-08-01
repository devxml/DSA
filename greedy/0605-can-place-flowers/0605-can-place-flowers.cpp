class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();

        for(int i = 0; i<len; i++){
            int curr = flowerbed[i];
            int left = (i == 0) ? 0 : flowerbed[i - 1];
            int right = (i == len - 1) ? 0 : flowerbed[i + 1];
            if(left == 0 && curr == 0 && right == 0){
                flowerbed[i] = 1;
                n--;
            }
        }
        if(n<=0){
            return true;
        }
        else {
            return false;
        }
    }
};