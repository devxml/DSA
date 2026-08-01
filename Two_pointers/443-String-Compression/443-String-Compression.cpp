class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> v;
        int n = chars.size();

        int c = 0;

        for (int i = 0; i < n; i++) {
            c++;
            if (i == n - 1 || chars[i] != chars[i + 1]) {
                v.push_back(chars[i]);

                if (c > 1) {
                   string s = to_string(c);
                   for (char a : s) {
                   v.push_back(a);
                    }
                }
                c = 0;
            }
        }

        chars = v;
        return chars.size();
    }
};