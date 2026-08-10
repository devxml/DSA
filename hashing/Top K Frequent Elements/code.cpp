class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        map<int, vector<int>> freq;

        for (auto [num, count] : mp) {
            freq[count].push_back(num);
        }

        vector<int> ans;

        for (auto it = freq.rbegin(); it != freq.rend() && ans.size() < k; it++) {
            for (int num : it->second) {
                ans.push_back(num);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};