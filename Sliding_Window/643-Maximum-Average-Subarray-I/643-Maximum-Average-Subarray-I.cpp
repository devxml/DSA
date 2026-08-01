class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        int n = nums.size();

        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        while (right < n - 1) {
            left++;
            right++;

            sum = sum - nums[left - 1] + nums[right];
            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};