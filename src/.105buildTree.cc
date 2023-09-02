#include "headers.h"

class Solution {
public:

    static int PreIndex;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        PreIndex = 0;
        return buildTree(preorder,inorder,0,inorder.size()-1);
    }
    int search(vector<int>& arr, int start, int end, int value)
    {
        int i;
        for (i = start; i <= end; i++)
        {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int left , int right){
        if(left > right) return nullptr;
        TreeNode* tNode = new TreeNode(preorder[PreIndex++]);

        if(left == right) return tNode;

        int inIndex = search(inorder,left,right,tNode->val);

        tNode->left = buildTree(preorder, inorder, left, inIndex - 1);
        tNode->right = buildTree(preorder,inorder,inIndex+1,right);
        return tNode;
    }
};

TEST(buildTree, 105buildTree_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.buildTree(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}