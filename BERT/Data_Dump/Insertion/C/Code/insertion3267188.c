#include<stdio.h>

#define MAX_N 1000

void insertionSort(int *, int);

int main()
{
  int A[MAX_N];
  int N=0;
  int i;
  
  scanf("%d", &N);

  for(i=0;i<N;i++)
   {
     scanf("%d",&A[i]);
   }

insertionSort(A,N);

  return 0;
}

void insertionSort(int *A, int N)
{
int i,j,v;

for(j=0;j<N;j++)
  {
if(j>0)printf(" ");
    printf("%d",A[j]);
  }
printf("\n");
for(i=1;i<N;i++)
  {
v = A[i];
j = i - 1;

while(j>=0 && A[j] > v)
  {
A[j+1] = A[j];
j--;
}
A[j+1] = v;

for(j=0;j<N;j++)
  {
if(j>0)printf(" ");
printf("%d",A[j]);
}
printf("\n");

}
}

