#include "headers.h"
#include <cstddef>
#include <map>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int top_k_347(vector<int>& nums) {
        // vector<vector<int>> freq(nums.size()+1);
        // unordered_map<int, int> hashmap; 
        // for(auto &num : nums){
        //     hashmap[num] += 1;
        // }
        // for(auto &d : hashmap){
        //     freq[d.second].push_back(d.first);
        // }

        // vector<int> res;
        // for(size_t i = freq.size()-1;i>=0;i--){
        //     for(auto &d : freq[i]){
        //         res.push_back(d);
        //         if(res.size() == k){
        //             return res;
        //         }
        //     }
        // }
        // return res;
        return 1;
    }
};

TEST(top_k_347, top_k_347_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.top_k_347(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}