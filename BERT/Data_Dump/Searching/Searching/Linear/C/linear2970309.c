#include<stdio.h>

int linearSearch(int n,int A[],int key){
  int i=0,j=0;
  A[n]=key;
  while(A[i]!=key)i++;
  return i;
}

int main(){
  int i,n,S[10000+1],q,T,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(linearSearch(n,S,T)!=n)sum++;
  }
  printf("%d\n",sum);
  return 0;
}
  

