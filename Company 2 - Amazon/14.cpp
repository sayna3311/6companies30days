#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* bfsToMapParent(Node* root, map<Node*,Node*> mp, int target)
{
    queue<Node*> q;
    q.push(root);
    Node* res;
    while (!q.empty())
    {
        /* code */
        Node* node = q.front();
        if(node->data==target) res = node;
        q.pop();
        if(node->left)
        {
            mp[node->left] = node;
            q.push(node->left);
        }
        if(node->right)
        {
            mp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int findMaxdistance(map<Node*,Node*> mp, Node* ans)
{
    queue<Node*> q;
    q.push(ans);
    map<Node*, int> vis;
    vis[ans] = 1;
    int maxi = 0;
    while (!q.empty())
    {
        int sz = q.size();
        int fl = 0;
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left])
            {
                vis[node->left] = 1;
                fl = 1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right])
            {
                vis[node->right] = 1;
                fl = 1;
                q.push(node->right);
            }
            if(mp[node] && !vis[mp[node]])
            {
                fl = 1;
                vis[mp[node]] = 1;
                q.push(mp[node]);
            }
        }
        if(fl) maxi++;
    }
    return maxi;
}

int solve(Node* root, int target)
{
    map<Node*, Node*> mp;
    Node* ans = bfsToMapParent(root,mp,target);
    int maxi = findMaxdistance(mp,ans);
    return maxi;
}

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        if (currVal != "N") {

            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}


int main()
{
    string s;
    cin>>s;
    int target;
    cin>>target;
    Node *root = buildTree(s);
    cout<<solve(root,target);
    return 0;
}
