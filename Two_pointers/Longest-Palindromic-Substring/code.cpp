class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, len = 1;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > len) {
                    len = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }

            // Even length palindrome
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > len) {
                    len = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, len);
    }
};