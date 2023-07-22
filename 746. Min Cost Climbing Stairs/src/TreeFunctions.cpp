#include <bits/stdc++.h>
#include "../lib/TreeFunctions.h"

void TreeFunction::PUSH_ELEMENTS_ARRAYTREE(vector<TreeNode *> &arr, string t)
{
    t = t.substr(1, t.size() - 2);
    stringstream ss(t);
    string argument;
    TreeNode *temp = nullptr;

    while (!ss.eof())
    {
        getline(ss, argument, ',');
        if (argument == "null")
        {
            arr.push_back(nullptr);
        }
        else
        {
            temp = new TreeNode(stoi(argument));
            arr.push_back(temp);
        }
    }
}

void TreeFunction::POPULATE_ARRAYTREE(vector<TreeNode *> &arr, string input)
{
    if (input[0] != '[' || input[input.size() - 1] != ']')
    {
        throw invalid_argument("Must be a valid array.");
    }
    this->PUSH_ELEMENTS_ARRAYTREE(arr, input);
}

void TreeFunction::DELETE_TREE(TreeNode *tree)
{
    if (!tree)
    {
        return;
    }
    DELETE_TREE(tree->left);
    DELETE_TREE(tree->right);
    delete tree;
}

void TreeFunction::DELETE_ELEMENTS(vector<TreeNode *> &arr)
{
    for (auto nodes : arr)
    {
        if (nodes)
        {
            delete nodes;
        }
    }

    arr.clear();
}

TreeNode *TreeFunction::Treeify(vector<TreeNode *> arr, int i, int n)
{
    if (arr.empty() || !arr[0])
    {
        return nullptr;
    }
    TreeNode *tree = nullptr;
    queue<TreeNode *> q;

    for (int i = 0; i < arr.size(); ++i)
    {
        q.push(arr[i]);
    }

    tree = q.front();
    q.pop();

    for (auto nodes : arr)
    {
        if (nodes)
        {
            if (!q.empty())
            {
                nodes->left = q.front();
                q.pop();
            }
            if (!q.empty())
            {
                nodes->right = q.front();
                q.pop();
            }
        }
    }

    return tree;
}