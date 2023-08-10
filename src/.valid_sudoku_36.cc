#include "headers.h"
#include <cstddef>
#include <cstring>
#include <limits>
#include <string>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int cols[9][9];
        int sub_boxs[9][9];

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(sub_boxs, 0, sizeof(sub_boxs));


        for(int i = 0;i<9;i++){
            for(int j = 0;j<9; j++){
                
                if(board[i][j] == '.') continue;

                int c = board[i][j]-'0'-1;
                int index_box = i / 3 * 3 + j / 3;
                rows[i][c]++;
                cols[j][c]++;
                sub_boxs[index_box][c]++;
                if(rows[i][c]>1 || cols[j][c]>1 || sub_boxs[index_box][c]>1)
                    return false;

            }
        }
        return true; 
    }
};

TEST(valid_sudoku_36, valid_sudoku_36_1)
{
    Solution s;
    vector<vector<char>> in = {{'8','8','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    int ans = 1;
    EXPECT_EQ(s.isValidSudoku(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}