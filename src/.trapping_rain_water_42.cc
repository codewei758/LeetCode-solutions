#include "headers.h"
#include <vector>

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        
        int res=0;
        for(int i=0; i<height.size(); i++)
        {
            while(!s.empty() && height[i] > height[s.top()])
            {
                int k = s.top();
                s.pop();
                if(!s.empty())
                {
                    int j = s.top();

                    int val = min(height[j], height[i]) - height[k];

                    res += val * (i - j -1);
                }
            }
            
            s.push(i);
    }
    return res;
    }
};

TEST(trapping_rain_water_42, trapping_rain_water_42_1)
{
    Solution s;
    vector<int> in = {4,2,0,3,2,5};
    int ans = 9;
    EXPECT_EQ(s.trap(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}