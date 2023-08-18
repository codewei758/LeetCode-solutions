#include "headers.h"

/*
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * */

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        unordered_set<char> se;
        int max_length = 0;
        int l = 0,r = 0;
        while (l <= r && r < s.size()){
            if(se.find(s[r]) == se.end())
            {
                se.insert(s[r]);
                max_length = max(max_length, r - l + 1);
                r++;
            }
            while(l < r && se.find(s[r]) != se.end())
            {
                se.erase(s[l]);
                l++;
            }
        }
        return max_length;
    }
};

TEST(lengthOfLongestSubstring_3, lengthOfLongestSubstring_3_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.lengthOfLongestSubstring((string &)"in"), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}