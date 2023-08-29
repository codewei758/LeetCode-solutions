#include "headers.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
        std::function<pair<bool,int>(TreeNode*)> dfs = [&](TreeNode* root){
            if(!root) return make_pair(true,0);
            auto right = dfs(root->right);
            auto left = dfs(root->left);

            if(abs(right.second-left.second) > 1)
                return make_pair(false,1 + max(right.second,left.second));


            return make_pair(right.first && left.first,1 + max(right.second,left.second));
        };

        return dfs(root).first;
    }
};

TEST(isBalanced_110, isBalanced_110_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.isBalanced(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}