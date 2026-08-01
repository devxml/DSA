class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i]>='0' && s[i]<='9')) {
                temp.push_back(tolower(s[i]));
            }
        }
        int start = 0;
        int end = temp.size()-1;

        while(start<end){
            if(temp[start]==temp[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};