#include "headers.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> queue1;
        queue1.push(root);


        while(!queue1.empty()){
            int n = queue1.size();
            vector<int> nums;
            while(n)
            {
                if (queue1.front()->left)
                {
                    queue1.push(queue1.front()->left);
                }
                if (queue1.front()->right)
                {
                    queue1.push(queue1.front()->right);
                }
                nums.push_back(queue1.front()->val);
                queue1.pop();
                n--;
            }
            res.push_back(nums);
        }
        return res;
    }
};

TEST(levelOrder_102, levelOrder_102_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.levelOrder(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}