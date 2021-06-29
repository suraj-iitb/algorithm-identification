#include <stdio.h>
#define N 100

int main()
{
  int b,c,i,j,k,v;
  int A[N];

  scanf("%d",&b);
  for(i=0;i<b;i++)
    scanf("%d",&A[i]);
   for(j=0;j<b;j++){
      printf("%d",A[j]);
      if(j<b-1) printf(" ");
    }
    printf("\n");
  for(i=1;i<b;i++){
    v=A[i];
    j=i-1;
    while((j>=0)&&(A[j]>v)){
	A[j+1]=A[j];
	j--;
     A[j+1]=v;
    }
    for(j=0;j<b;j++){
      printf("%d",A[j]);
      if(j<b-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}

