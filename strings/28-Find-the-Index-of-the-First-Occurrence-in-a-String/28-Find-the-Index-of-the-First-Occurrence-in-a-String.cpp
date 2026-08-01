class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n-m; i++) {
            int p1 = i;      
            int p2 = 0;

            while (p1 < n && p2 < m && haystack[p1] == needle[p2]) {
                p1++;
                p2++;
            }

            if (p2 == m) {   
                return i;
            }
        }

        return -1;
    }
};