class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;

        for(int i = 0; i < s.size(); i++) {

            if(smap.count(s[i]) && smap[s[i]] != t[i])
                return false;

            if(tmap.count(t[i]) && tmap[t[i]] != s[i])
                return false;

            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        }

        return true;
    }
};