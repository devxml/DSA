class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        int maxLen = min(str1.length(), str2.length());

        for (int i = maxLen; i > 0; i--) {

            if (str1.length() % i != 0 || str2.length() % i != 0)
                continue;

            string candidate = str1.substr(0, i);

            string temp = "";
            while (temp.length() < str1.length()) {
                temp += candidate;
            }

            if (temp != str1)
                continue;

            temp = "";
            while (temp.length() < str2.length()) {
                temp += candidate;
            }

            if (temp == str2)
                return candidate;
        }

        return "";
    }
};