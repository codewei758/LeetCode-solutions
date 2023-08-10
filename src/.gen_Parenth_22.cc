#include "headers.h"
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {};

        vector<string> total_l;
        total_l.push_back({});
        total_l.push_back({"()"});
        for(int i = 2;i<n+1;i++){
            vector<string> l;
            for(int j = 0;j<i;j++){
                auto now_list1 = total_l[j];
                auto now_list2 = total_l[i-1-j];
                for
            }
        }
    }
};

TEST(gen_Parenth_22, gen_Parenth_22_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.generateParenthesis(4), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}