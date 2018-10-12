#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> vals_to_index;
        for (int index = 0; (uint)index < nums.size(); ++index)
        {
            int other = target - nums[index];
            if (vals_to_index.find(other) != vals_to_index.end())
            {
                return vector<int> {index, vals_to_index[other]};
            }

            vals_to_index[nums[index]] = index;
        }

        return vector<int>{};
    }
};

int main(int argc, char** argv)
{
    Solution solver;
    vector<int> nums {10, 1, 5, 8, 22};

    auto ans = solver.twoSum(nums, 23);
    auto sln = vector<int> {1,4};
    std::sort (ans.begin(), ans.end());

    assert(sln == ans);

    return 0;
}
