#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



class Solution {
public:
    vector<bool> nums = vector<bool>(101, 0);
    Node* cloneGraph(Node* node) {
        if(!node) { return nullptr; }
        Node* cloneHead = new Node(node->val);
        if(node->neighbors.size() == 0) { return cloneHead; }

        queue<Node*> q;
        vector<Node*> createdNodes = vector<Node*>(101, nullptr);

        Node* currentNode = node;
        Node* currentCopyNode = cloneHead;

        q.push(node);
        createdNodes[currentCopyNode->val] = currentCopyNode;

        while(!q.empty()) {
            currentNode = q.front();
            currentCopyNode = createdNodes[currentNode->val];
            nums[currentNode->val] = 1;
            q.pop();

            for(int i = 0; i < currentNode->neighbors.size(); ++i) {
                int nodeVal = currentNode->neighbors[i]->val;
                if(!nums[nodeVal] && createdNodes[nodeVal]) {
                    currentCopyNode->neighbors.push_back(createdNodes[nodeVal]);
                    createdNodes[nodeVal]->neighbors.push_back(currentCopyNode);
                }
                else if(!nums[nodeVal]) {
                    Node* nnode = new Node(nodeVal);
                    createdNodes[nodeVal] = nnode;
                    currentCopyNode->neighbors.push_back(nnode);
                    nnode->neighbors.push_back(currentCopyNode);
                    q.push(currentNode->neighbors[i]);
                }
            }

        }

        return cloneHead;

        
    }
};

Node *buildGraph()
{
    /*
        Note : All the edges are Undirected
        Given Graph:
        1--2
        | |
        4--3
    */
    Node *node1 = new Node();
    node1->val = 1;
    Node *node2 = new Node();
    node2->val = 2;
    Node *node3 = new Node();
    node3->val = 3;
    Node *node4 = new Node();
    node4->val = 4;
    vector<Node *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbors = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbors = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbors = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbors = v;
    return node1;
}
 
int main() {

    Solution sol;
    Node* src = buildGraph();

    Node* ans = sol.cloneGraph(src);


    return 0;
}