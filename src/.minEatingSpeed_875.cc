#include "headers.h"
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxSpeed = 0;
        for(auto p : piles){
            maxSpeed = max(maxSpeed,p);
        }
        int res = maxSpeed;

        int l = 1 , r = maxSpeed;
        while(l <= r){
            int mid_speed = (l + r) / 2;
            long hour = 0; // 部分测试超过了int范围
            for(auto &p : piles){
                hour += (p % mid_speed > 0)? (p/mid_speed+1):(p/mid_speed);
            }
            if(hour <= h) {
                res = min(res,mid_speed);
                r = mid_speed - 1;
                }
            if(hour > h) l = mid_speed + 1;
        }
        return res;
    }
};

TEST(minEatingSpeed_875, minEatingSpeed_875_1)
{
    Solution s;
    vector<int> in = {3,6,7,11};
    int ans = 1;
    EXPECT_EQ(s.minEatingSpeed(in,8), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}