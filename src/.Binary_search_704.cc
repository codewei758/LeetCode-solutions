#include "headers.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        while(l < r){

            int mid = (l+r)/2;
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] > target) r = mid - 1;
            else return mid;
        }
        return -1;
    }
};

TEST(Binary_search_704, Binary_search_704_1)
{
    Solution s;
    vector<int> in = {-1,0,3,5,9,12};
    int ans = -1;
    EXPECT_EQ(s.search(in,2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}