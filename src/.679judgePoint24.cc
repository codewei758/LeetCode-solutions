#include "headers.h"

class Solution {
public:

    static constexpr double TARGET = 24.0;
    static constexpr double EPSILON = 1e-6;

    bool judgePoint24(vector<int>& cards) {
        vector<double> l;
        for(auto num : cards){
            l.emplace_back(double(num));
        }
        return solve(l);
    }

    vector<double> append(vector<double> d,double num){
        d.push_back(num);
        return d;
    }

    bool solve(vector<double> _l){
        int n = _l.size();
        if(n==1){
            return abs(_l[0]-TARGET) <= EPSILON;
        }
        bool isValid = false;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                const auto num1 = _l[i];
                const auto num2 = _l[j];

                vector<double> newNums;
                for (auto k = 0; k < n; k++) {
                    if (k != i && k != j) {  // 剔除掉选出的两个数
                        newNums.push_back(_l[k]);
                    }
                }

                isValid = isValid || solve(append(newNums,num2+num1));

                isValid = isValid || solve(append(newNums,num1 - num2));

                isValid = isValid || solve(append(newNums,num2 - num1));

                isValid = isValid || solve(append(newNums,num1 * num2));

                if(num1 != 0)
                {
                    isValid = isValid || solve(append(newNums,num2 / num1));
                }

                if(num2 != 0){
                    isValid = isValid || solve(append(newNums,num1 / num2));
                }

                if(isValid)
                    return true;
            }
        }
        return false;
    }
};

TEST(judgePoint24, judgePoint24_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    bool ans = true;
    EXPECT_EQ(s.judgePoint24(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}