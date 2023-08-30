#include "headers.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> queue1;
        queue1.push(root);

        while(!queue1.empty()){
            int n = queue1.size();
            res.push_back(queue1.front()->val);
            for(int i = 0;i<n;i++){
                auto node = queue1.front();
                queue1.pop();
                if(node->right){
                    queue1.push(node->right);
                }
                if(node->left){
                    queue1.push(node->left);
                }
            }
        }
        return res;
    }
};

TEST(rightSideView_199, rightSideView_199_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.rightSideView(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}