#include<stdio.h>
#include<stdlib.h>
#define K 10000
void CountingSort(int *,int *,int);

int main(){
  int n,i;
  int *A,*B;

  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*n);
  B=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  // printf("\na\n");

  CountingSort(A,B,n);

  for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(!(i==n-1)) printf(" ");
  }
  printf("\n");
  return 0;
}

void CountingSort(int *a,int *b,int n){
  int *c,*cc;
  int i,j;

  c=(int *)malloc(sizeof(int)*(K+1));
  cc=(int *)malloc(sizeof(int)*(K+1));

  for(i=0;i<=K;i++) c[i]=0;
  // printf("\nb\n");
  for(i=0;i<n;i++){
    c[a[i]]++;
  }


 //preparing for *cc
  i=0;
  while(1){
    if(i==0) cc[0]=c[0];
    else{
      cc[i]=c[i]+cc[i-1];
    }
    i++;
    if(i==K+1) break;
    } 

  //printf("\nb\n"); 
  for(j=n-1;j>=0;j--){
    b[cc[a[j]]-1]=a[j];
    cc[a[j]]--;
  } 
}
