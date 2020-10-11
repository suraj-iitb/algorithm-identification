#include<stdio.h>
int main(void)
{
 int N;
 scanf("%d", &N);
 int i,j,hozon,minj,A[N+1];
 int count = 0;
  
 for(i = 0; i < N; i++)
{
 scanf("%d",&A[i]);
}
 for(i = 0; i < N; i++)
{
  minj = i;
 for(j = i; j < N; j++)
{
 if(A[minj] > A[j])
{
 minj = j;
}
}
 if(minj != i)
{
  hozon = A[i];
  A[i] = A[minj];
  A[minj] = hozon;
  count++;
}
}
 for(i = 0; i < N; i++)
{
 if(i > 0)
 printf(" ");
 printf("%d",A[i]);
}
 printf("\n");
 printf("%d\n",count);
 return 0;

}
