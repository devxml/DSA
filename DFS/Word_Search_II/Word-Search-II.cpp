class Solution {
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;
    int m, n;

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];

        if (ch == '#' || !node->children[ch - 'a'])
            return;

        node = node->children[ch - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[r][c] = '#';

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                dfs(board, nr, nc, node);
            }
        }

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        m = board.size();
        n = board[0].size();

        for (string& word : words)
            insert(word);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};