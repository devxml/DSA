class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        unordered_map<string, int> mp;

        for (string word : words)
            mp[word]++;

        int n = words.size();
        int m = words[0].size();

        vector<int> ans;

        for (int i = 0; i < m; i++) {

            unordered_map<string, int> temp;

            int left = i;
            int right = i;
            int count = 0;

            while (right + m <= s.size()) {

                string str = s.substr(right, m);
                right += m;

                if (!mp.count(str)) {
                    temp.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                temp[str]++;
                count++;

                while (temp[str] > mp[str]) {
                    string leftWord = s.substr(left, m);
                    temp[leftWord]--;
                    left += m;
                    count--;
                }

                if (count == n) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, m);
                    temp[leftWord]--;
                    left += m;
                    count--;
                }
            }
        }

        return ans;
    }
};