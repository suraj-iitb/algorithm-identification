#include<stdio.h>
int search(int [],int ,int);
int main(){
  int i,n,a[10000+1],q,judge,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) {
    scanf("%d",&judge);
    if(search(a,n,judge))count++;
  }  
  printf("%d\n",count);
  return 0;
}

int search(int b[],int n,int key){
  int i=0;
  b[n]=key;
  while(b[i]!=key)i++;
  return i!=n;
}

