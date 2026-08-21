#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums){
    int left = 0;
        int ans = INT_MAX;
        int sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        if (ans == INT_MAX) {
            return 0;
        }

        return ans;
}

int main(){
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};

    int result = minSubArrayLen(target, nums);

    cout<<result;
    return 0;

}