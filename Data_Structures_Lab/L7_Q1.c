#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct {
    int size, f, r;
    char *a;
}Q;
int isFull(Q *q)
{
    if((q->r+1)%q->size==q->f)
        return 1;
    return 0;
}
int isEmpty(Q *q)
{
    if(q->f == q->r)
    return 1;
    return 0;
}
void insertq(Q *q, char* ele)
{
    if(isFull(q))
     {   printf("\nQueue full"); return;}
    
    q->r = (q->r+1)%q->size;
    (q->a[q->r]) = *ele;
    printf("\nElement inserted: %s, f=%d r=%d", ele,q->f,q->r);
}
void deleteq(Q *q)
{
    if(isEmpty(q))
    { printf("\nQueue empty"); return;}
    char *val;
     printf("f=%d r=%d",q->f,q->r);
    val = &(q->a[q->f]);
     q->f = (q->f+1)%q->size;
    printf("\nElement deleted: %s\n",val);
     printf("f=%d r=%d",q->f,q->r);
}
void disp(Q *q)
{
    int i;
    printf("\nDisplaying queue:\n");
    printf("\nf=%d r=%d\n",q->f,q->r);
    if(q->f < q-> r)
    {
    for(i = q->f; i<=q->r;i++)
        printf("%s\n",&(q->a[i]));
    }
    else
    {    for(i=q->r; i<q->f;i++)
          printf("%s\n",&(q->a[i]));
        for(i = q->f; i<q->size;i++)
         printf("%s\n",&(q->a[i]));
    }
}
void main()
{
    Q que, *q = &que;
    int n,ch=0;
    char ele[10],temp[10];
    printf("Enter size of Q: ");
    scanf("%d",&n);
    que.size = n;
    q->a = (char*)malloc(n*sizeof(char*));
    que.f = que.r = 0;
    printf("Enter: 1.InsertQ, 2.DeleteQ, 3. DisplayQ, 4. Exit: ");
    while(ch!=4)
    {
        printf("\nChoice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter element to insert: ");
            scanf("%s",ele);
            insertq(q,ele);
        }
        else if(ch==2)
            deleteq(q);
        else if(ch==3)
            disp(q);
    }
    printf("\nExit");
}