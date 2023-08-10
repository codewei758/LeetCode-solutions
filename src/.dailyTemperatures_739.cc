#include "headers.h"
#include <stack>
#include <utility>
#include <vector>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> res(temperatures.size(),0);
        for(int i = temperatures.size()-2 ;i>=0;i--){
            int j = i+1;
            while(temperatures[j] <= temperatures[i]){
                if(!res[j]) break;
                j += res[j];
            }
            if(temperatures[j] > temperatures[i]) res[i] = j-i;
        }
        return res;
    }
};

TEST(dailyTemperatures_739, dailyTemperatures_739_1)
{
    Solution s;
    vector<int> in = {73,74,75,71,69,72,76,73};
    vector<int> ans = {1,1,4,2,1,1,0,0};
    EXPECT_EQ(s.dailyTemperatures(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}