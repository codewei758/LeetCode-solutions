#include "headers.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int m = (int)s.size(),n = (int)t.size();
        if(m < n) return "";
        if(t=="") return "";

        unordered_map<char,int> sCount;
        unordered_map<char,int> tCount;
        for(int i = 0;i<n;i++){
            tCount[t[i]]++;

        }


        pair<int,int> res={-1,-1};
        int resLen = INT_MAX;

        int have = 0,need = tCount.size();

        int l = 0,r = 0;
        for(;r<m;r++){
            char c = s[r];
            sCount[c]++;

            if(tCount.contains(c) && sCount[c]==tCount[c])
                have++;

            while(have==need){
                if(r-l + 1 < resLen){
                    res = {l,r};
                    resLen = r-l+1;
                }
                sCount[s[l]]--;
                if(tCount.contains(s[l]) && sCount[s[l]] < tCount[s[l]])
                    have--;
                l++;
            }
        }
        l = res.first,r=res.second;
        if(resLen == INT_MAX) return "";
        else return s.substr(l,resLen);
    }
};

TEST(minWindow_76, minWindow_76_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.minWindow("cabefgecdaecf","cae"), "aec");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}