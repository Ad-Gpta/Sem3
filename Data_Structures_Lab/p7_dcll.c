//double circly linked list insertion and deletion and printing both ways (Without hearder node for now: )
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node* rlink;
    struct node* llink;
    int val;
} Node;
Node* getNode()
{
    Node* t = (Node*)malloc(sizeof(Node));
    t->val = -99; t->llink = NULL;t->rlink = NULL;
    return t;
}
void dispF(Node* h)
{
    Node*p = h;
    while(p->llink != h) {printf("->%d ",p->val);p=p->llink;}
}
void dispR(Node* h)
{
    Node*p = h;
    while(p->rlink != h) {printf("->%d ",p->val);p=p->rlink;}
}
Node* insert(Node* h,int v) //inserting elements in inc order
{
    Node* t = getNode();
    Node* p = h,*temp= NULL;
    t->val = v;
    while(p->llink!=h && ((p->llink->val)<v)) p = p->llink;
    temp = p->llink;
    p->llink = t;
    t->rlink = p;
    t->llink = temp;
    //h->rlink = t;
    return h;
}
void main()
{
    Node *h = getNode();
    int n,i,v;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter value of node %d: ",i+1);
        scanf("%d",&v);
        h = insert(h,v);
    }
    dispF(h);
    printf("\n");
    dispR(h);
}