#include "headers.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        int max_k = 1;
        int dp[n + 1][max_k + 1][2];
        ::memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= max_k; ++j)
            {
                if (i == 0)
                {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j-1][0] - prices[i]);
            }
        }
        return dp[n - 1][max_k][0];
    }
};

TEST(maxProfit_121, maxProfit_121_1)
{
    Solution s;
    vector<int> in = {7,1,5,3,6,4};
    int ans = 1;
    EXPECT_EQ(s.maxProfit(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}