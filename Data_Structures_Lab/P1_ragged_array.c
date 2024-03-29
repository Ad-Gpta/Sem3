#include<stdio.h>
#include<stdlib.h>
void main()
{
    int **p = (int**)calloc(5,sizeof(int*)); //number of rows; array of pointers to each row
    for(int i=0;i<5;i++)
    {
        p[i] = (int*)malloc((i+1)*sizeof(int)); //elements of individual rows
        for(int j = 0;j<(i+1);j++)
            p[i][j] = j;
    }
    for(int i=0;i<5;i++)
    {
        for(int j = 0;j<(i+1);j++)
           printf("\np[%d][%d]: %d",i,j,p[i][j]);
    }
}