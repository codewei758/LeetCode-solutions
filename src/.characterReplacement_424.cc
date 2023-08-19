#include "headers.h"

class Solution {
public:
    static int characterReplacement(string s, int k)
    {
        unordered_map<char,int> count;
        int res = 0;

        int l = 0,maxf =  0;
        int r = 0;
        int n = (int)s.size();
        for( ;r<n;r++){
            count[s[r]]++;
            maxf = max(maxf , count[s[r]]);

            while((r-l + 1) - maxf > k){
                count[s[l]] --;
                l++;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};

TEST(characterReplacement_424, characterReplacement_424_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.characterReplacement("AABABBA",1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}