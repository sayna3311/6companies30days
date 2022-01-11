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

void helper2(Node *root,vector<int>&a) 
{
    if(root==NULL)
    {
        a.push_back(int(NULL));
        return;
    }
    a.push_back(root->data);
    helper2(root->left,a);
    helper2(root->right,a);
    return ;
    
}
vector<int> serialize(Node *root) 
{
    vector<int>a;
    helper2(root,a);
    return a;
}

int idx=0;
Node * deSerialize(vector<int> &a)
{
    if((a.size()-1)<idx||a[idx]==NULL)
    {
        idx++;
        return NULL;
    }
    Node*root=new Node(a[idx++]);
    root->left=deSerialize(a);
    root->right=deSerialize(a);
    return root;
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

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node* node)  
{  
    if (node == NULL) return;  
    _deleteTree(node->left);  
    _deleteTree(node->right);  
    delete node;  
} 

void deleteTree(Node** node_ref)  
{  
    _deleteTree(*node_ref);  
    *node_ref = NULL;  
}  

int main()
{
    string t;
    cin>>t;
    Node* root = buildTree(t);
    vector<int> v = serialize(root);
    deleteTree(&root);
    Node* getRoot = deSerialize(v);
    inorder(getRoot);
    return 0;
}

