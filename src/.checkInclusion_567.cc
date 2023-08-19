#include "headers.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = (int)s1.size(),n2=(int)s2.size();
        if(n1 > n2) return false;

        int s1Count[26],s2Count[26];
        memset(s1Count,0,sizeof(s1Count));
        memset(s2Count,0,sizeof(s2Count));

        for(int i =0;i<n1;i++){
            s1Count[s1[i]-'a']++;
            s2Count[s2[i]-'a']++;
        }
        int matches = 0;
        for(int i =0;i<26;i++){
            if(s1Count[i] == s2Count[i]){
                matches++;
            }
        }

        for(int l = 0,r=n1;r<n2;r++){
            if(matches == 26) return true;

            int index = s2[r]-'a';
            s2Count[index]++;
            if(s1Count[index] == s2Count[index]) matches++;
            else if(s1Count[index]+1 ==s2Count[index]) matches--;

            int index_l = s2[l]-'a';
            s2Count[index_l]--;
            if(s1Count[index_l] == s2Count[index_l]) matches++;
            else if(s1Count[index_l]-1 ==s2Count[index_l]) matches--;

            l++;
        }
        if(matches==26) return true;
        return false;
    }
};

TEST(checkInclusion_567, checkInclusion_567_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.checkInclusion("in","in2"), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}