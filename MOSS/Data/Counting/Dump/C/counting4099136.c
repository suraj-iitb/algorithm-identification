#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define N 10000
int main()
{
unsigned short *X, *Y;

int A[N+1];
int kazu,i,j;
scanf("%d",&kazu);
X=malloc(sizeof(short)*kazu+1);
Y=malloc(sizeof(short)*kazu+1);
for(i=0;i<=N;i++)
A[i]=0;

for(i=0;i<kazu;i++)
{
scanf("%hu",&X[i+1]);
A[X[i+1]]++;
}
for(i=1;i<=N;i++)A[i]=A[i]+A[i-1];

for(j=1;j<=kazu;j++)
{
  Y[A[X[j]]]=X[j];
  A[X[j]]--;
}
for(i=1;i<=kazu;i++)
{
  if(i>1)printf(" ");
  printf("%d",Y[i]);
}
printf("\n");
  return 0;
}

