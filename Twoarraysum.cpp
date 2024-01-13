#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *ans;

        while (list1 != NULL && list2 != NULL)
        {

            if (list1->next != NULL)
            {

                list1 = list1->next;
            }

            
            if (list2->next != NULL)
            {

                list2 = list2->next;
            }






            cout << "list1 value: " << list1->val << endl;
            cout << "list2 value: " << list2->val << endl;

            list2 = list2->next;

            // if (list1->val <= list2->val)
            // {

            //     if (ans == NULL)
            //     {

            //         ans = new ListNode(list1->val);
            //         continue;
            //     }
            //     ans->next = new ListNode(list1->val);
            //     ans=ans->next;
            //     list1 = list1->next;
            // }

            // if (list2->val <= list1->val)
            // {
            //     ans->next = new ListNode(list2->val);
            //     ans=ans->next;
            //     list2 = list2->next;
            // }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{

    ListNode *list1 = new ListNode(11);
    list1->next = new ListNode(22);
    list1->next->next = new ListNode(33);
    ListNode *list2 = new ListNode(55);
    list2->next = new ListNode(66);
    list2->next->next = new ListNode(77);
    list2->next->next->next = new ListNode(88);

    Solution obj;
    obj.mergeTwoLists(list1, list2);

    return 0;
}
