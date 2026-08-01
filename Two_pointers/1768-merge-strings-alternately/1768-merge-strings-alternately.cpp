class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int m = word1.length();
        int n = word2.length();
        int i=0 , j=0;

        if(m>n || m==n){
            for(i = 0;i<m;i++){
                ans.push_back(word1[i]);
                
                if((j)!=n){
                ans.push_back(word2[j]);
                    j++;
                }
            }
        }
        if(m<n){
            for(j = 0;j<n;j++){
                
                

                if((i)!=m){
                ans.push_back(word1[i]);
                    i++;
                }
                ans.push_back(word2[j]);
            }
        }
        return ans;               
    }
};