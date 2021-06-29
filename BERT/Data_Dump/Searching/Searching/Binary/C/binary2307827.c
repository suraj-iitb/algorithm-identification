#include<stdio.h>

#define N 100000

int bserch(int a[], int b, int key){
  int i,left =0, right =b;

  while(left < right){
    i = (left+right)/2;
    if(a[i] == key){
      return 1;
    }
    else if(key < a[i]){
      right = i;
    }
    else{
      left = i +1;
    }
  }
  return 0;
}

int main(){
  int n, q, i, j, count = 0, discount = 0;
  int S[N],T[N];
  
   scanf("%d",&n);
  
  for(i=0; i<=n-1;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<=q-1;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<=q-1;i++){
    if(bserch(S,n,T[i]) == 1){
      count += 1;
    }
  }

  printf("%d\n", count);
  
  
  return 0;
}
