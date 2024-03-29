//concatenate 2 sll and reverse a sll
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}Node;
void disp(Node* h)
{
    Node* p = h;
    while(p) //iterates till p is null
    {
        printf("->%d",p->val);
        p = p->next;
    }
}
Node* create(Node* h, int n)
{
    Node* p = h;
    int v;
    for(int i=0;i<n;i++)
    {
        printf("\nval for node no %d: ",i+1);
        scanf(" %d",&v);
        if(h->val == -1) h->val = v;
        else 
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->val = v; temp->next = NULL;
        while(p->next != NULL)    p = p->next; //iterates till last element
        p->next = temp;
    }
    }
    return h;
}
Node* concat(Node* h1, Node* h2)
{
    Node*p = h1,*q = h2;
    while(p->next) p=p->next;
    p->next = q;
    return h1;
}
Node* rev(Node* h)
{
    Node*p = h->next->next, *trail = h,*mid = h->next;
    trail->next = NULL;
    while(p)
    {
        mid->next = trail;
        trail = mid;
        mid = p;
        p=p->next;
    }
    mid->next = trail;
    return mid;
}
void main()
{
    int n,v;
    Node* h1 = (Node*)malloc(sizeof(Node));
    Node* h2 = (Node*)malloc(sizeof(Node));
    h1->val = -1; h1->next = NULL;
    h2->val = -1; h2->next = NULL;
    printf("\nEnter number of elements for list1: ");
    scanf("%d",&n);
    h1 = create(h1, n);
    printf("\nh1: ");
    disp(h1);
    printf("\nEnter number of elements for list2: ");
    scanf("%d",&n);
    h2 = create(h2, n);
    printf("\nh2: ");
    disp(h2);
    Node* h3 = concat(h1,h2);
    printf("\nconcatenated list: ");
    disp(h3);
    printf("\nReversed list: ");
    h3 = rev(h3);
    disp(h3);
}