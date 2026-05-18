class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency map for characters in t
        unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int right = 0;

        int required = t.size(); // total characters still needed

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            // Include current character into window
            char c = s[right];

            // If this character is needed
            if (need[c] > 0) {
                required--;
            }

            // Reduce frequency
            need[c]--;

            right++;

            // When valid window found
            while (required == 0) {

                // Update minimum window
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // Remove left character
                char ch = s[left];

                need[ch]++;

                // If removing makes window invalid
                if (need[ch] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};