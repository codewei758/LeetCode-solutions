#include "headers.h"
#include <math.h>

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0,right = s.size()-1;
        while (left < right) {
            
            while(left < right && !alphanum(s[left])) left++;
            while(left<right && !alphanum(s[right])) right--;

            char l  = s[left];
            char r = s[right];
            if('A'<=l && l<= 'Z') l += 32;
            if('A'<=r && r<= 'Z') r += 32;

            if(l != r) return false;

            left++;
            right--;
        }
        return true;
    }

    bool alphanum(char c){
        return ('a'<= c && c<='z')||
                ('A'<=c && c<= 'Z')||
                ('0'<=c && c<= '9');
    }
};

TEST(valid_palindrome, valid_palindrome_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    string d = "A man, a plan, a canal: Panama";
    int ans = 1;
    EXPECT_EQ(s.isPalindrome(d), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}