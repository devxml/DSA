class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int backspace = 0;
        int i = s.size() - 1;
        while (s[i] == ' ') {
            backspace++;
            i--;
        }
        int j = s.size() - 1 - backspace;

        while (j >= 0 && s[j] != ' ') {
            ans++;
            j--;
        }
        return ans;
    }
};