#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y){
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}

int main(void){
  int A[100];
  int i,j,N,C,mini;
  int p,q;
  C=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    mini=i;
    for(j=i;j<N;j++){
      if(A[j]<A[mini]){
        mini=j;
      }
    }    p=A[i];
    q=A[mini];
    if (p>q)C++;
    swap(&p,&q);
    A[i]=p;
    A[mini]=q;
  }
  for(i=0;i<N;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",C);
  return 0;
}
