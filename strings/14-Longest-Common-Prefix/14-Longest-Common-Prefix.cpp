class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int j = 1; j < strs.size(); j++) {
            string ans = "";
            int i = 0;

            while (i < prefix.size() && i < strs[j].size() &&
                   prefix[i] == strs[j][i]) {
                ans += prefix[i];
                i++;
            }

            prefix = ans;

            if (prefix.empty())
                return "";
        }

        return prefix;
    }
};