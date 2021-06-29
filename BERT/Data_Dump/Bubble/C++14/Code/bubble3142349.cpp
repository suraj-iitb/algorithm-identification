#include<stdio.h>
void bubbleSort(int *A, int N, int *res)
{
    bool flag = true;
   for(int i=0;flag && i<N;i++)
   {
       flag=false;
       for(int j=N-1;j>i;j--)
       {
           if(A[j]<A[j-1])
           {
               int temp=A[j];
               A[j]=A[j-1];
               A[j-1]=temp;
               flag =true;
               *res=*res+1;
           }
       }
   }

}
int main()
{
    int N;
    int A[110];
    int res =0;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    bubbleSort(A,N, &res);
    for(int k=0;k<N;k++)
    {
        if(k>0)
        {
            printf(" ");
        }
        printf("%d",A[k]);
    }
    printf("\n%d\n",res);
}
