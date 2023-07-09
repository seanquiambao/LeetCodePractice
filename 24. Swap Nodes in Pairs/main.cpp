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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* temp = nullptr;
        while(true) {
            temp = prev;
            prev->next = curr->next;
            curr->next = temp;
            if(prev == head) head = curr;

            prev = prev->next; 
            if(prev == nullptr) break;
            curr = prev->next;
        }

        return head;
    }
};


int main() {

    Solution sol;
    vector<int> arr = {1,2,3,4};
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for(int i = 1; i < arr.size(); ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    sol.swapPairs(head);

    return 0;
}