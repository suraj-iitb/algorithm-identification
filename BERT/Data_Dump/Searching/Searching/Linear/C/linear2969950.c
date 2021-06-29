#include <stdio.h>

int linearSearch(int *,int);

int length=0;

int main(){
  int n=0;
  int q=0;
  int i=0;
  int count=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d", &T[i]);
  }
  length=sizeof(S)/sizeof(int);
  for(i=0;i<q;i++){
    if(linearSearch(S,T[i])==1)
      count++;
  }
  printf("%d",count);
  printf("\n");

  return 0;
}

int linearSearch(int *A,int key){
  int i=0;
  A[length]=key;
  while(A[i]!=key){
    i++;
    if(i==length) return 0;
  }
  return 1;
}

