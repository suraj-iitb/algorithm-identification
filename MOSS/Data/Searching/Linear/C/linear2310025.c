#include <stdio.h>
int linearsearch(int A[],int n,int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key)i++;
  return i!=n;
}
int main(){
  int i,n,A[10001],q,key,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(linearsearch(A,n,key))sum++;
  }
  printf("%d\n",sum);
  return 0;
}
