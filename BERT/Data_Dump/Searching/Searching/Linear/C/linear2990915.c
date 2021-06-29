#include<stdio.h>
int search(int [],int ,int);
int main(){
  int i,n,A[10000+1],q,judge,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) {
    scanf("%d",&judge);
    if(search(A,n,judge))count++;
  }
  printf("%d\n",count);
  return 0;
}

int search(int a[],int n,int key){
  int i=0;
  a[n]=key;
  while(a[i]!=key)i++;
  return i!=n;
}

