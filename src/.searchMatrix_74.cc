#include "headers.h"
#include <algorithm>
#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size(),COLS = matrix[0].size();
        int up = 0,down = ROW-1;
        int row = 0;
        while (up <= down) {
            row = (up + down) /2 ;
            if(target > matrix[row][COLS-1])
                up = row + 1;
            else if(target < matrix[row][0])
                down = row - 1;
            else
                break;
        }
        int l = 0,r = COLS - 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(matrix[row][mid] < target) l = mid + 1;
            else if(matrix[row][mid] > target) r = mid - 1;
            else return true;
        }
        return false;
    }
};

TEST(searchMatrix_74, searchMatrix_74_1)
{
    Solution s;
    vector<vector<int>> in = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int ans = 1;
    EXPECT_EQ(s.searchMatrix(in,3), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}