#include "headers.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        function<void(TreeNode*)> dfs = [&](TreeNode* node){
            if(!node)
            {
                res.emplace_back("N");
                return;
            }
            res.push_back(to_string(node->val));
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        string finalRes;
        for(const auto& c : res){
            finalRes += c + ",";
        }
        return finalRes;
    }

    vector<string> split(const string &data,const char pattern){
        vector<string> res;
        stringstream input(data);
        string temp;
        while(getline(input,temp,pattern))
        {
            res.push_back(temp);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        auto dataList = split(data,',');
        int i = 0;

        function<TreeNode*()> dfs = [&](){
            TreeNode* node = nullptr;
            if(dataList[i]=="N")
            {
                i++;
                return node;
            }
            node = new TreeNode(stoi(dataList[i]));
            i++;
            node->left = dfs();
            node->right = dfs();
            return node;
        };
        return dfs();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

TEST(Serialize_DeBT, Serialize_DeBT_1)
{
    Codec s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.serialize(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}