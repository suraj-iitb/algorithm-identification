#include <stdio.h>

int linersearch(int n,int A[],int key){
  int i=0;
  for(i=0;i<n-1;i++){
    if(A[i]==key)return 1;
  }
    return 0;
}

int main(){
  int n,q,A[10000],key;
  int i,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    count=count+linersearch(n,A,key);
  }
  printf("%d\n",count);

  return 0;
}

