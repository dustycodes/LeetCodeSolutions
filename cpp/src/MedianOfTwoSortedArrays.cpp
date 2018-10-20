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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0.0;

        return median;
    }
};

void test_example(vector<int>& nums1, vector<int>& nums2, double solution)
{
    Solution solver;
    auto ans = solver.findMedianSortedArrays(nums1, nums2);
    assert(ans == solution);

    std::cout << "Passed: " << solution << std::endl;
}

int main(int argc, char** argv)
{
    vector<int> v1, v2;

    v1.push_back(1);
    v1.push_back(3);
    v2.push_back(2);
    test_example(v1, v2, 2.0);

    v1.clear();
    v2.clear();

    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    test_example(v1, v2, 2.5);

    return 0;
}
