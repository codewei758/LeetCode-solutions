#include "headers.h"
#include <cstddef>
#include <set>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    vector<int> two_sum_1(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for(std::size_t i = 0;i<nums.size();i++){
            auto cp = hashmap.find(target - nums[i]);

            if(cp!=hashmap.end()){
                return {cp->second,(int)i};
            }
            else{
                hashmap[nums[i]] = i;
            }
        }
        return {};
    }
};

TEST(two_sum_1, two_sum_1_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int in2 = 4;
    int ans = 1;
    EXPECT_EQ(s.two_sum_1(in,in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}