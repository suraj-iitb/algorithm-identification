#include<stdio.h>
#define N 100
void bubbleSort(int[], int);

int main()
{
  int i,j,k,temp,n,A[N];
  scanf("%d",&n);
  for (i=0; i<=n-1; i++)
{
  scanf("%d",&A[i]);
}
  bubbleSort(A,n);
return 0;
}
void bubbleSort(int A[],int n)
{
  int i,j,k,temp;
  int count=0;
  for(i=0; i<=n-1; i++)
    {  
      for(j=n-1; j>=i+1; j--)
        {
          if(j>=0 && A[j] < A[j-1])
            {
              temp = A[j];
              A[j] = A[j-1];
              A[j-1] = temp;
              count++;
            }
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

