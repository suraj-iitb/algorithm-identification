#include<stdio.h>

#define NOT_FOUND 0

int linearSearch(int A[],int n,int key){
  int i=0;
  A[n] = key;
  while(A[i]!=key){
    i++;
  if(i==n){
    return NOT_FOUND;
  }
}
  return 1;
}
  int main(){
    int i,n,A[10000+1],q,key,s=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d",&key);
      if(linearSearch(A,n,key)){
        s++;
      }
    }printf("%d\n",s);

    return 0;
  }

