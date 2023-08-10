#include "headers.h"
#include <algorithm>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0,end = nums.size()-1;

        while (st <= end){
            int mid = (st + end) / 2;
            if(nums[mid] == target) return mid;

            if(nums[st] <= nums[mid]){
                
                if(target > nums[mid] || target < nums[st])
                    st = mid + 1;
                else
                    end = mid - 1;

            }else {
                if(target < nums[mid] || target > nums[end])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
        }
        return -1;
    }
};

TEST(search_33, search_33_1)
{
    Solution s;
    vector<int> in = {4,5,6,7,0,1,2};
    int ans = 1;
    EXPECT_EQ(s.search(in,0), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}