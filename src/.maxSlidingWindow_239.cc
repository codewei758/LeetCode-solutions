#include "headers.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int l = 0,r = 0,n = (int)nums.size();

        deque<int> q; // index

        while(r < n){
            while(!q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);

            if(q[0] < l) q.pop_front();

            if(r-l+1>=k){
                res.push_back(nums[q[0]]);
                l++;
            }
            r++;
        }

        return res;
    }
};

TEST(maxSlidingWindow_239, maxSlidingWindow_239_1)
{
    Solution s;
    vector<int> in = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = {3,3,5,5,6,7};
    EXPECT_EQ(s.maxSlidingWindow(in,3), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}