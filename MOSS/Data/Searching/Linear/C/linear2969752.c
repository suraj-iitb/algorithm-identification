#include<stdio.h>

int serch(int A[],int n,int key){
  int c=0;
  A[n]=key;
  while(A[c]!=key){
    c++;
  }
  return c!=n;
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
    if(serch(A,n,key))sum++;
  }

  printf("%d\n",sum);

  return 0;

}

