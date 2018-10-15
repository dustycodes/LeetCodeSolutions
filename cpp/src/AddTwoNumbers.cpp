#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = new ListNode(0);
        ListNode* first = ans;
        int sum = 0, overflow = 0;
        int temp1Val = 0, temp2Val = 0;

        while (temp1 != nullptr || temp2 != nullptr)
        {
            if (temp1 != nullptr)
            {
                temp1Val = temp1->val;
                temp1 = temp1->next;
            }
            else
                temp1Val = 0;

            if (temp2 != nullptr)
            {
                temp2Val = temp2->val;
                temp2 = temp2->next;
            }
            else
                temp2Val = 0;

            sum = temp1Val + temp2Val + overflow;
            overflow = sum / 10;

            if (overflow <= 0)
            {
                overflow = 0;
                ans->next = new ListNode(sum);
            }
            else
            {
                ans->next = new ListNode(sum - 10*overflow);
            }
            ans = ans->next;
        }
        if (overflow > 0)
            ans->next = new ListNode(overflow);

        return first->next;
    }

    void printNode(ListNode* n)
    {
        ListNode* temp = n;
        while (temp != nullptr)
        {
            std::cout << temp->val;
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void check(long long int solution, ListNode* ans)
    {
        ListNode* temp = ans;

        long long number = 0;
        long long i = 1;
        while (temp != nullptr)
        {
            number += ((long long)temp->val * i);
            i *= 10;
            temp = temp->next;
        }

        assert(solution == number);
    }
};

int main(int argc, char** argv)
{
    Solution solver;

    ListNode* n = new ListNode(2);
    n->next = new ListNode(4);
    n->next->next = new ListNode(3);

    ListNode* n2 = new ListNode(5);
    n2->next = new ListNode(6);
    n2->next->next = new ListNode(4);

    ListNode* ans = solver.addTwoNumbers(n, n2);
    solver.printNode(ans);
    solver.check(807, ans);
    //
    // n = new ListNode(9);
    // n2 = new ListNode(1);
    // ListNode* tempNode = n2;
    // for (int i = 0; i < 9; ++i)
    // {
    //     tempNode->next = new ListNode(9);
    //     tempNode = tempNode->next;
    // }
    //
    // ListNode* ans = solver.addTwoNumbers(n, n2);
    // solver.printNode(ans);
    // solver.check(10000000000, ans);
    //
    // ListNode* ones1 = new ListNode(1);
    // ListNode* ones2 = new ListNode(1);
    // ListNode* temp1 = ones1;
    // ListNode* temp2 = ones2;
    // for (int i = 0; i < 10; i++)
    // {
    //     temp1->next = new ListNode(1);
    //     temp2->next = new ListNode(1);
    //
    //     temp1 = temp1->next;
    //     temp2 = temp2->next;
    // }
    // ListNode* ans2 = solver.addTwoNumbers(ones1, ones2);
    // solver.printNode(ans2);
    // solver.check(22222222222, ans2);
    //
    // ListNode* test1 = new ListNode(1);
    // ListNode* test2 = new ListNode(5);
    // test2->next = new ListNode(6);
    // test2->next->next = new ListNode(4);
    //
    // temp1 = test1;
    // for (int i = 0; i < 10; i++)
    // {
    //     temp1->next = new ListNode(1);
    //
    //     temp1 = temp1->next;
    // }
    // ListNode* ans3 = solver.addTwoNumbers(test1, test2);
    // solver.printNode(ans3);
    // // solver.check(1000000000000000000000000000466, ans3);

    ListNode* single1 = new ListNode(9);
    ListNode* single2 = new ListNode(9);
    ListNode* ansSingle = solver.addTwoNumbers(single1, single2);
    solver.printNode(ansSingle);
    solver.check(18, ansSingle);

    return 0;
}
