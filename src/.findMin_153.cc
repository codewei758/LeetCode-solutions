#include "headers.h"
#include <algorithm>
#include <climits>

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0,end = nums.size()-1;
        int res = INT_MAX;
        while (start < end) {
            int mid = (start + end) / 2;
            res = min(res,nums[mid]);

            if(nums[mid] < nums[end]) end = mid - 1;
            else{
                start = mid + 1;
            }
        }
        return min(res,nums[start]);
    }
};

TEST(findMin_153, findMin_153_1)
{
    Solution s;
    vector<int> in = {4,5,6,7,0,1,2};
    int ans = 1;
    EXPECT_EQ(s.findMin(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}