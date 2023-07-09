#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L1curr = l1;
        ListNode* L2curr = l2;
        ListNode* ListSum = nullptr;
        ListNode* curr = ListSum;
        int sum = 0;
        int carry = 0;

        while(L1curr || L2curr) {
            sum = 0;
            if(L1curr == nullptr) {
                sum = carry + L2curr->val;
                L2curr = L2curr->next;
            } 
            else if (L2curr == nullptr) {
                sum = carry + L1curr->val;
                L1curr = L1curr->next;
            }
            else {
                sum = carry + L2curr->val + L1curr->val;
                L1curr = L1curr->next;
                L2curr = L2curr->next;
            } 

            if(sum > 9) {
                sum -= 10;
                carry = 1;
            }
            else carry = 0;
            
            if(ListSum == nullptr) {
                curr = new ListNode(sum);
                ListSum = curr;
            }
            else {
                curr->next = new ListNode(sum);
                curr = curr->next;
            }
            
            
        }
        if(carry != 0) curr->next = new ListNode(carry);

        return ListSum;
    }
};

int main() {

    Solution sol;
    vector<int> list1 = {0};
    vector<int> list2 = {0};

    ListNode* num1 = new ListNode(list1[0]);
    ListNode* num2 = new ListNode(list2[0]);
    ListNode* curr = num1;
    for(int i = 1; i < list1.size(); ++i) {
        curr->next = new ListNode(list1[i]);
        curr = curr->next;
    } 
    curr = num2;
    for(int i = 1; i < list2.size(); ++i) {
        curr->next = new ListNode(list2[i]);
        curr = curr->next;
    }

    ListNode* numSum = sol.addTwoNumbers(num1, num2);
    return 0;
}