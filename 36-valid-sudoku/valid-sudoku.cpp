class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Hash sets for rows, cols and boxes
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> cols(9, vector<int>(9, 0));
        vector<vector<int>> boxes(9, vector<int>(9, 0));
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue; // empty cell
                
                int num = board[i][j] - '1';   // convert char to index (0–8)
                int boxIndex = (i/3) * 3 + (j/3); // which 3x3 box
                
                if(rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                    return false; // already present
                }
                
                rows[i][num] = 1;
                cols[j][num] = 1;
                boxes[boxIndex][num] = 1;
            }
        }
        return true;
    }
};
