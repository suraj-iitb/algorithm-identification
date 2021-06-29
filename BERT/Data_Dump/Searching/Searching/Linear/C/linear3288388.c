#include<stdio.h>
int linearSearch(int A[],int i,int key);
int main(){
  int i,n,o,A[10001],key,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&o);
  for(i=0;i<o;i++){
    scanf("%d",&key);
    if(linearSearch(A,n,key)!=-1){
      sum++;
    }
  }
  printf("%d\n",sum);
  return 0;
}
int linearSearch(int A[],int n,int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key){
    i++;
  }
  if(i==n){
    return -1;
  }
  return i;
}
  

