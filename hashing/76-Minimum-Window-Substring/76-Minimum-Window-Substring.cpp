class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int right = 0;

        int required = t.size();

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            char c = s[right];

            if (need[c] > 0) {
                required--;
            }

            need[c]--;

            right++;

            while (required == 0) {

                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                char ch = s[left];

                need[ch]++;

                if (need[ch] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};