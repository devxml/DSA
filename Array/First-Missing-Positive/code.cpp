class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1:
        // Any number <= 0 or > n cannot be the answer,
        // so replace it with n + 1.
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2:
        // Use the array itself as a hash table.
        // If number x exists, make nums[x-1] negative.
        for (int i = 0; i < n; i++) {

            // Get the original value because it may already be negative.
            int num = abs(nums[i]);

            // Ignore n+1 since it was our dummy value.
            if (num > n)
                continue;

            // Convert value to index.
            // 1 -> index 0
            // 2 -> index 1
            // ...
            // n -> index n-1
            num--;

            // Mark as visited only once.
            if (nums[num] > 0)
                nums[num] = -nums[num];
        }

        // Step 3:
        // First positive index means that number is missing.
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        // Step 4:
        // All numbers 1...n are present.
        return n + 1;
    }
};