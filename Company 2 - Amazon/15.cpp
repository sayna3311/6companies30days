#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}


void linkdelete(struct Node  *head, int M, int N)
{  
    if(head == NULL) return;
    
    int c = 0;
    while(head != NULL && head->next){
        c++;
        if(c == M){
            struct Node* cur = head;
            int temp = N;
            while(temp--){
                if(cur->next) cur=cur->next;
            }
            head->next = cur->next;
            c = 0;
        }
        head = head->next;
    }
    
}


int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}