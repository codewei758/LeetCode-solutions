#include "headers.h"
#include <algorithm>
#include <cstring>
#include <vector>


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int *parent;
        memset(parent, 0, sizeof(nums));
    }

    int find(int u,int *parent){
        if(parent[u] != u){
            parent[u] = find(parent[u], parent);
        }
        return parent[u];
    }

    void uion(int u,int v,int *parent,int *size){
        int _u = find(u, parent);
        int _v = find(v, parent);
        if(_u != _v){
            parent[v] = u;
            size[u] += size[v];
        }
    }

    
};

TEST(longest_con_seq_128, longest_con_seq_128_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.longestConsecutive(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}