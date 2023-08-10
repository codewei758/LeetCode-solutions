#include "headers.h"
#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> sta; // pair(index , height)
        int maxArea = 0;
        int n = heights.size();
        for(int i = 0;i<n;i++){
            int start = i;
			int h = heights[i];
            
			while (!sta.empty() && sta.rbegin()->second > h){
				int index = sta.rbegin()->first;
				int height = sta.rbegin()->second;
                sta.pop_back();
				maxArea =  max(maxArea,height * (i-index));
                start = index;
			}
            sta.push_back(pair(start,h));
        }

        for(int i = 0;i<sta.size();i++){
            int h = sta[i].second;
            maxArea = max(maxArea,h * (n-sta[i].first));
        }
        return maxArea;
    }
};

TEST(largestRectangleArea_84, largestRectangleArea_84_1)
{
    Solution s;
    vector<int> in = {2,1,5,6,2,3};
    int ans = 10;
    EXPECT_EQ(s.largestRectangleArea(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}