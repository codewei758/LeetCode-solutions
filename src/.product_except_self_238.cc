#include "headers.h"
#include <cstddef>
#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> res(nums.size());
        int prefix = 1;
        for(int i = 0;i<nums.size();i++){
            
            res[i] = prefix;
            prefix  *= nums[i];
        }

        int postfix = 1;
        for(int i = nums.size()-1 ;i>=0;i--){
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};

TEST(product_except_self_238, product_except_self_238_1)
{
    Solution s;
    vector<int> in = {1,2,3,4};
    vector<int> ans = {24,12,8,6};
    EXPECT_EQ(s.productExceptSelf(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}