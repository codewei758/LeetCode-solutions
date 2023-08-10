#include "headers.h"
#include <map>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        unordered_map<char, char> ma = {{')','('},{']','['},{'}','{'}};
        for(auto c : s){
            if(ma.find(c) == ma.end()){
                sta.push(c);
                continue;
            }
            if(sta.empty() || sta.top()!=ma[c]){
                return false;
            }
            sta.pop();
        }
        return sta.empty();
    }
};

TEST(valid_parenth_20, valid_parenth_20_1)
{
    Solution s;
    string in = "()[]{}";
    int ans = 1;
    EXPECT_EQ(s.isValid(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}