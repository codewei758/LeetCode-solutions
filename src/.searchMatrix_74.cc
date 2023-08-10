#include "headers.h"

class Solution
{
public:
    int searchMatrix_74(vector<int> &nums)
    {
        return 1;
    }
};

TEST(searchMatrix_74, searchMatrix_74_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.searchMatrix_74(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}