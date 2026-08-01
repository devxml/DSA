class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        int count = 0;
        int left = 0;
        nums[0] = nums[left];
        for(int right = 0; right<nums.size(); right++){
            if(nums[left]!=nums[right]){
                nums[index] = nums[right];
                index++;
                left = right;
                count++;
            }
        }
        return count+1;
    }
};