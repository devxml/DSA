class Solution {
public:
    string reverseWords(string s) {
        int end = s.size() - 1;
        string ans = "";

        while (end >= 0) {
            while (end >= 0 && s[end] == ' ') {
                end--;
            }

            if (end < 0)
                break;

            int start = end;

            while (start >= 0 && s[start] != ' ') {
                start--;
            }

            if (!ans.empty()) {
                ans += " ";
            }

            ans += s.substr(start + 1, end - start);

            end = start - 1;
        }

        return ans;
    }
};