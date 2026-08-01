class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> arr;
        int n = candies.size();
        int max = 0;

        for(int i = 0; i < n; i++){
            if(candies[i]>max){
                max = candies[i];
            }
        }
        for(int i = 0; i<n; i++){
            if((extraCandies + candies[i])>= max){
                arr.push_back(true);
            }
            else{
                arr.push_back(false);
            }
        }
    return arr;
    }
};