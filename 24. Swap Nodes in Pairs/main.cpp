#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createList(vector<int> arr) { 
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(int i = 1; i < arr.size(); ++i) { 
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }


    return head;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) { return head; }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextPtr = head;
        head = curr->next;

        while(curr && curr->next) {
            nextPtr = curr->next;
            curr->next = nextPtr->next;
            nextPtr->next = curr;
            if(prev) { prev->next = nextPtr; }
            curr = curr->next;
            prev = nextPtr;
        }
        return head;
    }
};

int main() {


    ListNode* list = createList({1,2,3,4});
    Solution sol;
    ListNode* ans = sol.swapPairs(list);

    while(ans) { 
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    


    return 0;
}