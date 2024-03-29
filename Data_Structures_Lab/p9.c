//circular queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct{
    int a[MAX];
    int f;
    int r;
}Q;
void disp(Q* q)
{
    if(q->r<q->f)
    {
    for(int i=q->f;i<MAX;i++)
        printf(" %d ",q->a[i]);
    for(int i=0;i<=q->r;i++)
        printf(" %d ",q->a[i]);
    }
    else
    {
        for(int i=q->f;i<=q->r;i++)
        printf(" %d ",q->a[i]);
    }
}
void enqueue(Q* q, int v)
{
    q->r = (q->r+1)%MAX;
    if(q->r == q->f){ printf("\nQueue full\n"); q->r++;}
    else{
    q->a[q->r] = v;
    printf("\ncurrent Q: ");
    disp(q);
    }
}
int dequeue(Q* q)
{
    if(q->r == q->f){ printf("\nQueue empty\n"); return -99;}
    int v = q->a[q->f];
    q->f = (q->f+1)%MAX;
    return v;
}
void main()
{
    Q* q = (Q*)malloc(sizeof(Q));
    q->a[0] = -99; q->f = 0; q->r = 0;
    int ch=0,v;
    printf("Enter:\n1. push\n2. pop\n3. disp\n4. exit: ");
    while(ch!=4)
    {
        printf("\nChoice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter val: "); scanf("%d",&v); enqueue(q,v); break;
            case 2: v = dequeue(q); printf("popped value: %d",v); break;
            case 3: disp(q); break;
            case 4: printf("\nExit");
        }
    }
}
