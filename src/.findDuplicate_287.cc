#include "headers.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
        int len = nums.size();
        unsigned long index_bit[(len/64+1)]; // 低位在开头
        memset(index_bit,0,sizeof(index_bit));
        for(auto n : nums){
            unsigned int i = 0;
            int num = n;
            if(n%64 == 0)
            {
                i = n / 64 - 1;
                n = 64;
            }
            else{
                i = n/64;
                n = n%64;
            }
            unsigned long  bit = ((long(1) << (n-1)) & index_bit[i]);
            if(!bit){ // 结果为 0 说明 n-1 位置的数不存在
                index_bit[i] = index_bit[i] | (long(1) << (n-1));
            }
            else{
                return num;
            }
        }
        return -1;
    }
};

TEST(findDuplicate_287, findDuplicate_287_1)
{
    Solution s;
    vector<int> in = {75,75,75,75,75,91,75,75,75,75,75,75,30,75,75,78,75,75,75,75,75,7,79,93,75,75,15,75,75,75,75,75,75,4,75,75,21,75,75,19,75,59,75,76,75,75,75,75,75,75,75,33,75,75,75,58,75,75,5,75,97,81,48,42,75,87,75,75,25,27,94,20,75,75,75,29,75,75,86,67,75,75,75,65,75,75,75,75,75,39,75,56,75,75,75,75,3,75,75,75};
    int ans = 75;
    EXPECT_EQ(s.findDuplicate(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}