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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* currentNode = head;
        ListNode* nextNode = currentNode->next;
        while(nextNode != nullptr){

            if(currentNode->val == nextNode->val) {
                currentNode->next = nextNode->next;
                delete nextNode;
                nextNode = currentNode->next;
            }
            else {
                currentNode = nextNode;
                if(nextNode != nullptr) nextNode = nextNode->next;
            }
            
        }

        return head;
    }
};

int main(){

    vector<int> vals = {1,1,1};
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for(int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    Solution sol;

    sol.deleteDuplicates(head);

    

    while(curr != nullptr){
        cout << curr->val << ", ";
        curr = curr->next;
    }

    return 0;
}