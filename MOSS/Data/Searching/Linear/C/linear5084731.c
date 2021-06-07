#include<stdio.h>
#define MAX 10000
int Search();
int main(){
  int A[MAX],i,n,q,count=0,key;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(Search(A,key,n)==1) count++;
  }
  printf("%d\n",count);
  return 0;
}
int Search(int A[],int key,int n){
  int i=0;
    A[n] = key;
  while(A[i] != key)
    i++;
  if(i == n) return 0;
  return 1;

}

