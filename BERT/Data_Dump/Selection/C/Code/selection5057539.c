#include<stdio.h>
#define N 100
void selectionSort(int[], int);

int main()
{
  int i,n,A[N];
  scanf("%d",&n);
  for (i=0; i<=n-1; i++)
{
  scanf("%d",&A[i]);
}
  selectionSort(A,n);
return 0;
}
void selectionSort(int A[],int n)
{
  int i,j,k,temp,minj;
  int count=0;
  for(i=0; i<=n-2; i++)
    {
      minj = i;
      for(j=i; j<=n-1; j++)
        {
          if(A[j] < A[minj])
            {
              minj = j;
            }
        }
          if(i != minj)
          {
              temp = A[i];
              A[i] = A[minj];
              A[minj] = temp;
              count++;
          }
    }


    for(k=0; k<n-1; k++)
      {
        printf("%d ",A[k]);
      }
    printf("%d",A[n-1]);
    printf("\n");
    printf("%d\n",count);
}
