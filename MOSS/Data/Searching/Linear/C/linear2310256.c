#include<stdio.h>
#define NOT_FOUND 0
int A[10000];
int n;
int linearSearch(int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key){
    i++;
    if(i==n){
      return NOT_FOUND;
    }
  }
  return 1;
}
int main(){
  int i,key,a,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&key);
    if(linearSearch(key)) cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}
