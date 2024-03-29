//stack basics
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int tos;
    int a[5];
}stack;
void disp(stack s)
{
    for(int i=0;i<s.tos;i++)
        printf("%d ",s.a[i]);
}
int isFull(stack* s)
{
    if(s->tos == 4) return 1;
    else return 0;
}
int isEmpty(stack* s)
{
    if(s->tos == -1) return 1;
    else return 0;
}
void push(stack *s, int val)
{
    if(isFull(s))
    {
        printf("\nOverflow!"); 
    }
    else
    s->a[++(s->tos)] = val;
}
int pop(stack *s)
{
    if(isEmpty(s))
    {
        printf("\nUnderflow\n");
        return 0;
    }
    return s->a[(s->tos)--];
}
void main()
{
    int ch=0, v;
    stack stk, *s = &stk; s->tos = -1; 
    printf("Enter:\n1. push\n2. pop\n3. disp\n4. exit: ");
    while(ch!=4)
    {
        printf("\nChoice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter val: "); scanf("%d",&v); push(s,v); break;
            case 2: v = pop(s); printf("popped value: %d",v); break;
            case 3: disp(*s); break;
            case 4: printf("\nExit");
        }
    }
}