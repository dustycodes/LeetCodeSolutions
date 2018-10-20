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
    int lengthOfLongestSubstring(string s) {
        queue<char> sequence;
        set<char> hasher;
        int longest = 0;

        for (char c : s)
        {
            // Found, Remove it
            if (hasher.find(c) != hasher.end())
            {
                while (sequence.front() != c)
                {
                    hasher.erase(sequence.front());
                    sequence.pop();
                }
                sequence.pop();
                hasher.erase(c);
            }

            hasher.insert(c);
            sequence.push(c);
            longest = (((uint)longest < sequence.size()) ? sequence.size() : longest);
        }
        return longest;
    }
};

void test_example(string input, int solution)
{
    Solution solver;
    int ans = solver.lengthOfLongestSubstring(input);
    assert(ans == solution);

    std::cout << "Passed: '" << input << "' " << solution << std::endl;
}

int main(int argc, char** argv)
{
    test_example("abcabcbb", 3);
    test_example("bbbbb", 1);
    test_example("pwwkew", 3);
    test_example("dvdf", 3);
    test_example("asljlj", 4);
    test_example("ggububgvfk", 6);

    return 0;
}
