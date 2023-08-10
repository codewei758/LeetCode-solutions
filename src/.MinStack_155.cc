#include "headers.h"
#include <climits>
#include <deque>
#include <stack>
#include <vector>

class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        sta.push(val);
        if(min_stack.empty()) min_stack.push(val);
        else
         min_stack.push(min(min_stack.top(),val));
    }
    
    void pop() {
        sta.pop();
        min_stack.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
protected:
    stack<int> sta;
    stack<int> min_stack;
};

TEST(MinStack_155, MinStack_155_1)
{
    MinStack s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.getMin(), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}