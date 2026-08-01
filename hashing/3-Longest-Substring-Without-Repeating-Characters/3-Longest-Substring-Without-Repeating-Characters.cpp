class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0;
        int maxlen = 0;
        int len = 0;

        for(int right = 0; right<s.size(); right++){
            while(set.count(s[right])){
                set.erase(s[left]);
                left++ ;
            }
            set.insert(s[right]);
            len = right - left + 1;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};