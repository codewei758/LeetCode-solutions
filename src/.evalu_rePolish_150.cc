#include "headers.h"
#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        for(auto s : tokens){
            if(s[0] >= '0' && s[0] <= '9' or (s.length()>1 && s[0]=='-')){
                sta.push(std::stoi(s));
                continue;
            }
            if(s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'){
                int i = 0,j = 0;
                switch (s[0]) {
                    case '+':
                        i = sta.top();
                        sta.pop();
                        j = sta.top();
                        sta.pop();
                        sta.push(i+j);
                        break;
                    case '-':
                        i = sta.top();
                        sta.pop();
                        j = sta.top();
                        sta.pop();
                        sta.push(j-i);
                        break;
                    case '*':
                        i = sta.top();
                        sta.pop();
                        j = sta.top();
                        sta.pop();
                        sta.push(i*j);
                        break;
                    case '/':
                        i = sta.top();
                        sta.pop();
                        j = sta.top();
                        sta.pop();
                        sta.push(j / i);
                        break;
                }
            }
        }
        return sta.top();
    }
};

TEST(evalu_rePolish_150, evalu_rePolish_150_1)
{
    Solution s;
    vector<string> in = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int ans = 22;
    EXPECT_EQ(s.evalRPN(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}