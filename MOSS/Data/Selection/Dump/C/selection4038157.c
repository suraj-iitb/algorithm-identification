#include<stdio.h>
#define LIM 100

void *Sels(int *,int *);

int main() {

  int N,num[LIM];
  int i,j;

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&num[i]);

  j=N;
  Sels(num,&N);
  
  for(i=0;i<j;i++) {
    if(i>0) printf(" ");
    printf("%d",num[i]);
  }

  printf("\n%d\n",N);

  return 0;

}

void *Sels(int *num,int *a) {

  int N=*a;
  int minj;
  int i,j,k;
  *a=0;

  for(i=0;i<=N-1;i++) {
    minj = i;

    for(j=i;j<=N-1;j++) {
      if(num[j] < num[minj]) minj = j;
    }
    k=num[i]; num[i] = num[minj]; num[minj] = k;
    if(i!=minj) *a=*a+1;
  }
}
