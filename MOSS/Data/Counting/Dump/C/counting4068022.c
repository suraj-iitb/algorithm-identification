#include <stdio.h>
#define M 2000001

int c[M],A[M],B[M];

int search(int);
void counting(int,int);

int main(void){
  int i,j,m,k;
  int limit;
  scanf("%d",&limit);
  for(i=1;i<=limit;i++){
    scanf("%d",&A[i]);
  }
  k=search(limit);
  counting(limit,k);
  for(i=1;i<limit;i++){
    printf("%d ",B[i]);
    }
  printf("%d\n",B[limit]);
  return 0;
}

void counting(int limit,int k){
  int i,j;
  for(i=0;i<=k;i++){
    c[k]=0;
  }
  for(i=1;i<=limit;i++){
    c[A[i]]++;
  }
  for(i=1;i<=k;i++){
    c[i]=c[i]+c[i-1];
  }
  for(j=limit;j>0;j--){
    B[c[A[j]]]=A[j];
    c[A[j]]--;
  }
}

int search(int limit){
  int i=0,x=0;
  for(i=1;i<=limit;i++){
    if(x<A[i])x=A[i];
  }
  return x;
}

