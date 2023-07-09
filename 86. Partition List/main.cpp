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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return NULL;
        partition(head->next, x);
        if(head->next->val < x) return NULL;
        int temp = head->val;
        head->val = head->next->val;
        head->next->val = temp;
        return head;
    }
};

int main() {

    Solution sol;
    vector<int> Case1 = {1,4,3,2,5,2};
    ListNode* head = new ListNode(Case1[0]);
    ListNode* curr = head;
    for(int i = 1; i < Case1.size(); ++i) {
        ListNode* newNode = new ListNode(Case1[i]);
        curr->next = newNode;
        curr = curr->next;
    }

    ListNode* partitionedList = sol.partition(head, 3);
    curr = partitionedList;
    while(curr != nullptr) {
        cout << curr->val << ", ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}