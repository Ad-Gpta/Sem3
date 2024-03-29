#include<stdio.h>
#include<stdlib.h>
//linked lists
typedef struct node{
    int val;
    struct node *link;
}NODE;
NODE* insert_end(NODE *h,int ele)
{
    NODE *p = h,*temp;
    temp = (NODE*)malloc(sizeof(NODE));
    while(p->link!= NULL)
        p= p->link;
    temp->val = ele;
    temp->link = NULL;
    p->link = temp;
    return h;
}
NODE* insert_mid(NODE *h, int ele, int test)
{
    NODE *p = h, *temp;
    while(p->val != test)
    {
        p = p->link;
        if (p->link == NULL) break;
    }
    printf("p val: %d",p->val);
    if(p->val != test)
    {
        printf("\nValue not there in list");
        return h;
    }
    temp = (NODE*)malloc(sizeof(NODE));
    temp->val = ele;
    temp->link = (p->link);
    p->link = temp;
    return h;
}
NODE* del(NODE *h, int ele)
{
    printf("start");
    if(h->link = NULL)
    {
        printf("\nEmpty list\n");
        return h;
    }
    if(h->val == ele)
    {
        //first element needs to be deleted
        h = h->link;
        return h;
    }
    printf("mid");
    NODE *p= h, *trail,*temp;
    while(p->val!=ele)
    {    
        trail = p;
        p = p->link;
    }
    printf("\np val after searching: %d",p->val);
    temp = p;
    p = p->link;
    trail-> link = p;
    //free(temp);
    return h;
}
void disp(NODE *h)
{
    printf("\nDisplaying list: ");
    while(h->link != NULL)
    {    
        printf("->%d ",h->val);
        h = h->link;
    }
     printf("->%d ",h->val);
}
void main()
{
    printf("Started program");
    NODE *head = NULL;
    NODE *first;
    first = (NODE*)malloc(sizeof(NODE));
    first ->val = 0; first -> link = NULL;
    head = first;
    head = insert_end(head, 1);
    printf("\nInserted 1\n");
    head = insert_end(head, 2);
    printf("\nInserted 2\n");
     disp(head);
    printf("\nEnter 3 b/w 1 and 2:\n");
    head = insert_mid(head,3,1);
    disp(head);
    printf("\nDeleting 3: \n");
    del(head, 3);
    disp(head);
}