#include<stdio.h>
#include<stdlib.h>

void sort(int[],int);
void tra(int[],int);
int main()
{
    int N,A[100],i;
    scanf("%d",&N);
        
    for(i=0; i<N; i++)        scanf("%d",&A[i]);
    
    tra(A,N);
    sort(A,N);
    
    return 0;
}   

void sort(int A[],int N)
{
    int i,j,v;
    for(i=1; i<N; i++)
    {
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v)
        {
            A[j+1]=A[j];
            j--;
        }  
        A[j+1]=v;
        tra(A,N);
    }
}

void tra(int A[],int N)
{
    int i;
    for(i=0; i<N; i++)
    {
      
       if(i>0)  printf(" ");
      
       printf("%d",A[i]);
    }
    printf("\n");
}

