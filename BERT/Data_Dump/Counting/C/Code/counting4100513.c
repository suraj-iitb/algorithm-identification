#include<stdio.h>
#include<stdlib.h>
#define N 2000001
#define M 10000

int main()
{
  unsigned short *x,*y;
  int a[M+1];
  int s,i,j,k;

  scanf("%d",&s);

  x=malloc(sizeof(short)*s+1);
  y=malloc(sizeof(short)*s+1);

  for(i=0;i<=M;i++)a[i]=0;

  for(i=0;i<s;i++){
    scanf("%hu",&x[i+1]);
    a[x[i+1]]++;
  }
  for(i=1;i<=M;i++)a[i]=a[i]+a[i-1];

  for(j=1;j<=s;j++){
		      
    y[a[x[j]]]=x[j];
    a[x[j]]--;
  }
  for(i=1;i<=s;i++){
    if(i>1)printf(" ");
    printf("%d",y[i]);
  }
  printf("\n");

  return 0;
}

