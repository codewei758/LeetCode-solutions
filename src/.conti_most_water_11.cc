#include "headers.h"
#include <algorithm>
#include <cmath>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i,j;
        int mysize = height.size();
        
        if(mysize <= 1) {
            return 0;
        }
        
        if(mysize == 2) {
            return min(height[0], height[1]);
        }
        
        int max_area = 0;
        
        int left = 1;
        int right = mysize;
        
        while(left < right) {
            int current = (right - left) * min(height[left-1], height[right-1]);
            max_area = max(max_area, current);
            if(height[left-1] < height[right-1]) {
                left++;
                max_area = max(max_area, (right - left) * min(height[left-1], height[right-1]));
            }
            else if(height[left-1] > height[right-1]) {
                right--;
                max_area = max(max_area, (right - left) * min(height[left-1], height[right-1]));
            }
            else {
                left++;
                right--;
                max_area = max(max_area, (right - left) * min(height[left-1], height[right-1]));
            }
        }

        
        return max_area;
    }
};

TEST(conti_most_water_11, conti_most_water_11_1)
{
    Solution s;
    vector<int> in = {1,8,6,2,5,4,8,3,7};
    int ans = 49;
    EXPECT_EQ(s.maxArea(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}