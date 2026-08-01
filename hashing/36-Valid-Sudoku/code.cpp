class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        set<char> rows[9];
        set<char> cols[9];
        set<char> boxes[9];

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.')
                    continue;

                char x = board[i][j];

                int box = (i / 3) * 3 + (j / 3);

                if(rows[i].count(x))
                    return false;

                if(cols[j].count(x))
                    return false;

                if(boxes[box].count(x))
                    return false;

                rows[i].insert(x);
                cols[j].insert(x);
                boxes[box].insert(x);
            }
        }

        return true;
    }
};