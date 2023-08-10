#include "headers.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0,j = numbers.size()-1;
        while(i < j){
            if(target-numbers[i] < numbers[j]) j--;
            if(target-numbers[i] > numbers[j]) i++;
            if(target-numbers[i] == numbers[j])
                return {i+1,j+1};
        }
        return {};
    }
};

TEST(two_sum_2_167, two_sum_2_167_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int in2 = 4;
    int ans = 1;
    EXPECT_EQ(s.twoSum(in,in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}