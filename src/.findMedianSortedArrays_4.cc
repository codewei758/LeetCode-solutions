#include "headers.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = (int)A.size();
        int n = (int)B.size();

        if(m > n) return findMedianSortedArrays(B,A);

        int iMin = 0,iMax = m;

        while(iMin <= iMax){
            int i = (iMax + iMin) / 2;
            int j = (m+n+1) / 2 -i;

            if(j!=0 && i!=m && B[j-1] > A[i]){
                iMin = i+1;
            }
            else if(i!=0 && j!=n && A[i-1] > B[j]){
                iMax = i-1;
            }
            else{
                int maxLeft = 0;
                if (i == 0) { maxLeft = B[j-1]; }
                else if (j == 0) { maxLeft = A[i-1]; }
                else { maxLeft = max(A[i-1], B[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; } // 奇数的话不需要考虑右半部分

                int minRight = 0;
                if (i == m) { minRight = B[j]; }
                else if (j == n) { minRight = A[i]; }
                else { minRight = min(B[j], A[i]); }

                return (maxLeft + minRight) / 2.0; //如果是偶数的话返回结果
            }
        }
        return 0.0;
    }
};

TEST(findMedianSortedArrays_4, findMedianSortedArrays_4_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    vector<int> in2 = {3,4,5,6,7,9};
    int ans = 1;
    EXPECT_EQ(s.findMedianSortedArrays(in,in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}