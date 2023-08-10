#include "headers.h"
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    vector<vector<string>> group_anagrams_49(vector<string> &strs)
    {
        map<vector<int>, vector<string>> res;
        for(auto &s : strs){
            vector<int> count(26,0);
            for(auto &c : s){
                count[int(c-'a')] += 1;
            }
            res[count].push_back(s);
        }
        vector<vector<string>> re;
        for(auto &r:res){
            re.push_back(r.second);
        }
        return re;
    }
};

TEST(group_anagrams_49, group_anagrams_49_1)
{
    Solution s;
    vector<string> in = {"1", "2", "3"};
    int ans = 1;
    EXPECT_EQ(s.group_anagrams_49(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}