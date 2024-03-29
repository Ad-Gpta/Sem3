//testing and relearning structures
#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
typedef struct{
    int d,m,y;
}DOB;
typedef struct{
    int id;
    char name[50]; //Complex structures: arrays within structures
    DOB dob; //Complex structures: nested structures
}ID;
void disp(ID a[], int n) //passing structures to fcn through array
//void disp(ID *a, int n) //passing structures to fcn through pointer
{
    for(int i=0;i<n;i++)
    {
        printf("\nFor record num: %d",i+1);
        printf("\nID: %d",a[i].id); //works; using array
        //printf("\nID: %d",(a+i)->id); //works; using pointer to array //selection operator: ->
        printf("\nName: %s\n",a[i].name);
        printf("DOB: %d/%d/%d\n",(a[i].dob.d),(a[i].dob.m),(a[i].dob.y));
    }
}
void main()
{
    printf("Enter number of records: ");
    int n;
    scanf("%d",&n);
    ID a[n]; //Complex structures: arrays of structures
    ID* p = a;
    for(int i=0;i<n;i++)
    {
        printf("\nEnter id and name and dob(dd, mm, yy) for record number %d: ",i+1);
        scanf("%d",&(a[i].id)); //a[i] = value of that index or arraw is a struct; a[i].id = member of just ref struct
        scanf(" %s",&(a[i].name));
        scanf("%d%d%d",&(a[i].dob.d),&(a[i].dob.m),&(a[i].dob.y));
    }
    disp(a,n);
}