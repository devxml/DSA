class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;

        for(int i = 0; i<magazine.size(); i++){
            mp[magazine[i]]++;
        }

        unordered_map<char,int> Rmp;


        for(int i = 0; i<ransomNote.size(); i++){
            Rmp[ransomNote[i]]++;
        }

        for(auto it : Rmp){
            if(mp[it.first]<it.second){
                return false;
            }
        }
        return true;
    }
};