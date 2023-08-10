#include "headers.h"
#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();++i){
            if(i > 0 and nums[i]==nums[i-1])    continue;
            int left = i+1,right = nums.size()-1;
            
            while(left < right){
                int threesum = nums[i] + nums[left] + nums[right];
                if(threesum > 0){
                    right--;
                }
                else if(threesum<0){
                    left++;
                }
                else{
                    res.push_back({nums[i],nums[right],nums[left]});
                    left++;
                    while (nums[left] == nums[left-1] && left < right) {
                        left++;
                    }
                }
            }
            
        }
        return res;
    }

    vector<int> twoSum(vector<int>& numbers,int right,int left, int target) {
       
        while(right < left){
            if(target-numbers[right] < numbers[left]) left--;
            if(target-numbers[right] > numbers[left]) right++;
            if(target-numbers[right] == numbers[left])
                return {right+1,left+1};
        }
        return {numbers[right],numbers[left]};
    }
};
TEST(threeSum_15, threeSum_15_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.threeSum(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}