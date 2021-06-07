#include<stdio.h>

int binarySearch(int a[],int key,int n){
  int left=0;
  int right=n;
  int mid;

  while(left<right){
    mid=(left+right)/2;
    if(a[mid]==key){return mid;}
    else if(key<a[mid]){right=mid;}
    else{left=mid+1;}
  }
  return n+1;
}

int main(void){
  int count=0,judge;
  int i,n,s[100000],q,t[50000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  for(i=0;i<q;i++)
    {
      judge=binarySearch(s,t[i],n);
      if(judge!=n+1){count++;}
    }
  printf("%d\n",count);
  return 0;
}
