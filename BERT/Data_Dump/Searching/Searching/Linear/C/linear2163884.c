#include <stdio.h>


int linearSearch(int A[],int n,int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key){
    i++;
  }
  return i!=n;
}

int main(void){
  int n,q,i,sum=0;
  scanf("%d",&n);
  int s[n];
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  int t[q];
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    if(linearSearch(s,n,t[i])){
      sum++;
    }
  }

  printf("%d\n",sum);
  return 0;
}
