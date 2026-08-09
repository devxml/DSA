class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int count = 0;
        bool found = false;

        for (auto i : s) {
            mp[i]++;
        }

        for (auto i : mp) {
            if (i.second % 2 == 0) {
                count += i.second;
            }
            else {
                count += i.second - 1;  // take the even portion

                if (!found) {
                    count++;
                    found = true;
                }
            }
        }

        return count;
    }
};