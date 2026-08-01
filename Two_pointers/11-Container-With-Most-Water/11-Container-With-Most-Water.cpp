class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxstorage = 0;
        int maxheight = 0;
        while(start<end){
            maxheight = min(height[start],height[end]);

            maxstorage = max(maxstorage,maxheight*(end-start));

            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return maxstorage;
    }
};