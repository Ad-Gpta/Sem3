#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int a[10],f1,f2,r1,r2;
}Q;
void enq1(Q *q, int ele)
{
    //int start = 0, end = 5;
    int size = 5;
    printf("\nbefore dding element: f1= %d r1= %d\n",q->f1,q->r1);
    if((q->r1+1)%size==q->f1)
        printf("\nQ1 full\n");
    else if(q->r1 =0)
        q->a[q->r1] = ele;
    else
    {
        int n = (q->r1+1)%size;
        q->r1 = n;
        printf("\nnew r1: f1= %d r1= %d\n",q->f1,q->r1);
        q->a[q->r1] = ele;
    }
     printf("\nf1= %d r1= %d\n",q->f1,q->r1);
}
void enq2(Q *q, int ele)
{
    //int start = 9, end = 5;
    int size = 5,max = 10;
    if((q->r2+size)%max==q->f2-4)
        printf("\nQ2 full\n");
    else if(q->r2 =9)
        q->a[q->r2] = ele;
    else
    {
        q->r2 = (q->r2-1+size)%max;
        q->a[q->r2] = ele;
    }
     printf("\nf2= %d r2= %d\n",q->f2,q->r2);
}
void delQ1(Q *q)
{
    if(q->r1==q->f1)
    {
        printf("\nQ1 empty");
        return;
    }
    int val = q->a[q->f1];
    q->f1+=1;
    printf("\nElement deleted in Q1: %d",val);
     printf("\nf1= %d r1= %d\n",q->f1,q->r1);
}
void delQ2(Q *q)
{
    if(q->r2==q->f2)
    {
        printf("\nQ2 empty");
        return;
    }
    int val = q->a[q->f2];
    q->f2-=1;
    printf("\nElement deleted in Q2: %d",val);
     printf("\nf2= %d r2= %d\n",q->f2,q->r2);
}
void disp(Q *q)
{
    int i;
    printf("\nQ1: \n");
    if(q->f1 == q->r1)
    printf("\nQ1 empty");
    else
    {
        printf("\nf1= %d r1= %d\n",q->f1,q->r1);
        if(q->f1<q->r1)
            for(i=q->f1+1;i<=q->r1;i++)
                printf("%d\t",q->a[i]);
        else
        {
            for(i=q->f1+1;i<5;i++)
                printf("%d\t",q->a[i]);
            for(i=0;i<=q->r1;i++)
                printf("%d\t",q->a[i]);
        }
    }
    printf("\nQ2: \n");
    if(q->f2 == q->r2)
    printf("\nQ2 empty");
    else
    {
        printf("\nf2= %d r2= %d\n",q->f2,q->r2);
        if(q->f2<q->r2)
            for(i=q->f2+1;i<q->r2;i++)
                printf("%d\t",q->a[i]);
        else
        {
            for(i=q->f2+1;i<10;i++)
                printf("%d\t",q->a[i]);
            for(i=5;i<=q->r2;i++)
                printf("%d\t",q->a[i]);
        }
    }
}
void main()
{
    Q que, *q = &que;
    que.f1= que.r1=0; 
    que.f2=que.r2=9;
    int ch=0,ele;
    printf("\nEnter:\n1.Insert q1\n2.Insert q2\n3. delete q1\n4. delete q2\n5. display\n6. exit");
    while(ch!=6)
    {
        printf("\nChoice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter element: "); scanf("%d",&ele);
            enq1(q,ele); break;
            case 2: printf("\nEnter element: "); scanf("%d",&ele);
            enq2(q,ele); break;
            case 3: delQ1(q); break;
            case 4: delQ2(q); break;
            case 5: disp(q); break;
            case 6: printf("\nExit"); break;
            default: printf("\nInvalid choice\n");
        }
    }
}