class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                // Delete left character
                int l1 = left + 1;
                int r1 = right;

                bool checkLeft = true;

                while (l1 < r1) {
                    if (s[l1] != s[r1]) {
                        checkLeft = false;
                        break;
                    }
                    l1++;
                    r1--;
                }

                // Delete right character
                int l2 = left;
                int r2 = right - 1;

                bool checkRight = true;

                while (l2 < r2) {
                    if (s[l2] != s[r2]) {
                        checkRight = false;
                        break;
                    }
                    l2++;
                    r2--;
                }

                return checkLeft || checkRight;
            }
        }

        return true;
    }
};