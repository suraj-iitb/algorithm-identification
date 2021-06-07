#include<stdio.h>

int linearSearch(int[],int,int);

int main(){
  int i, n, q, key, number=0, S[10000];

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&key);
    if(linearSearch(S,n,key) != -1) number++;
  }

  printf("%d\n",number);

  return 0;
}

int linearSearch(int A[], int x, int y){
  int i;

  for(i = 0 ; i < x ; i++){
    if(A[i] == y){
      return i;
    }
  }
  return -1;
}
  

