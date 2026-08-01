class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int maxgain = 0;
        for(int right = 1; right<prices.size(); right++){
            int gain = prices[right] - prices[left];
            if(gain>0){
                maxgain = gain + maxgain;
            }
            left++;
        }
        return maxgain;
    }
};    