class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int res = 0;
        for(int right = 0; right<prices.size(); right++){
            int gain = prices[right]-prices[left];
            if(gain<0){
                left = right;
            }
            res = max(gain,res);
        }
        return res;
    }
};