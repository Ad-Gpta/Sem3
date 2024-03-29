#include<stdio.h>
 enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};
 //enum week{1,2,3,4,5,6,7};
void main()
{
   
   
    enum week d1=1;
    enum week d2=5;
    enum week d3 = Sun;
    printf("day 1: %d",d1);
    printf("\nday 2: %d",d2);
    printf("\nday 3: %d",d3);
}