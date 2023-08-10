#include "headers.h"
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

class Solution {
public:
     int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> par;
        for(int i = 0;i < position.size();i++){
            par.push_back({position[i],speed[i]});
        }

        sort(par.begin(),par.end(),[&](pair<int, int> &a, pair<int, int> &b){
            return a.first > b.first;}
        );

        int ans = 1;
        int p1 = par[0].first, s1 = par[0].second;
        for (int i = 1; i < position.size(); ++i) {
            int p2 = par[i].first, s2 = par[i].second;
            //乘法判定 避免浮点数计算精度损失
            if ((long long)(target - p1) * s2 < (long long)(target - p2) * s1) {
                ++ans;
                p1 = p2;
                s1 = s2;
            }
        }
        return ans;
    }
};

TEST(carFleet_853, carFleet_853_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.carFleet(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}