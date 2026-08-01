class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                v[j] = nums[i];
                j++;
            }
        }

        nums = v;
    }
};