#include<stdio.h>

#define N 100000

int lineSearch(int *, int, int);

int main(){
  int n,q,i,j;
  int S[N];
  int c,count = 0;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
    scanf("%d",&q);
  
  for(j = 0;j < q;j++){
    scanf("%d",&c);
    if(lineSearch(S,n,c)) count++;
  }
  printf("%d\n",count);
}

int lineSearch(int A[],int n,int key){
  int i;
  for(i = 0;i < n -1;i++){
    if(A[i] == key){
      return 1;
    }
  }
  return 0;
}


