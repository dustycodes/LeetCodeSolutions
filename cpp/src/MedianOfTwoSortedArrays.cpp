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
        int size = nums1.size() + nums2.size();
        int middle = (size / 2);
        int nums3[size];

        int i1 = 0, i2 = 0;
        int i3 = 0;
        while (i1 < nums1.size() && i2 < nums2.size())
        {
            if (i1 > middle + 1 && i2 > middle + 1)
                break;

            if (nums1[i1] < nums2[i2])
                nums3[i3++] = nums1[i1++];
            else
                nums3[i3++] = nums2[i2++];
        }

        while (i1 < nums1.size() && i1 < middle + 1)
            nums3[i3++] = nums1[i1++];

        while (i2 < nums2.size() && i2 < middle + 1)
            nums3[i3++] = nums2[i2++];

        if (size % 2 == 0)
        {
            median = (nums3[middle - 1] + nums3[middle]) / 2.0;
        }
        else
        {
            median = nums3[middle];
        }

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

    v1.clear();
    v2.clear();

    v2.push_back(2);
    v2.push_back(3);
    test_example(v1, v2, 2.5);


    return 0;
}
