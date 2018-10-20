#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest_pal = "";

        return longest_pal;
    }
};

void test_example(string s, vector<string> possible_answers)
{
    Solution solver;
    auto ans = solver.longestPalindrome(s);

    bool found = false;
    for (auto sol : possible_answers)
    {
        if (sol == ans)
        {
            found = true;
            break;
        }
    }

    assert(found == true);

    std::cout << "Passed: " << ans << std::endl;
}

int main(int argc, char** argv)
{
    // Example 1:
    test_example("babad", vector<string> {"bab", "aba"});

    // Example 2:
    test_example("cbbd", vector<string> {"bb"});

    return 0;
}
