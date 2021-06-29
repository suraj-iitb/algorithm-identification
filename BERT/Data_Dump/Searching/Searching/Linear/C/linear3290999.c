#include <stdio.h>
#define S 1000000

int search(int A[S],int n, int key){
  int i;
  A[n]=key;
  for(i=0 ; A[i]!=key ; i++){}
  return i != n;
}

int main(){
  int i=0,n,A[S],q,key,sum=0;
  scanf("%d" ,&n);
  while(i<n){
    scanf("%d",&A[i]);
    i++;
  }
  scanf("%d",&q);
  i=0;
  while(q!=i){
    
    scanf("%d",&key);
    if(search(A,n,key)){
      sum++;
    }
    i++;
  }
  printf("%d\n",sum);
  return 0;
}

