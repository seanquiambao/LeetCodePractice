#ifndef __TREEFUNCTIONS_H__
#define __TREEFUNCTIONS_H__
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeFunction
{
public:
    void POPULATE_ARRAYTREE(vector<TreeNode *> &arr, string input);
    void PUSH_ELEMENTS_ARRAYTREE(vector<TreeNode *> &arr, string t);
    void DELETE_TREE(TreeNode *tree);
    void DELETE_ELEMENTS(vector<TreeNode *> &arr);
    TreeNode *Treeify(vector<TreeNode *> arr, int i, int n);
};

#endif