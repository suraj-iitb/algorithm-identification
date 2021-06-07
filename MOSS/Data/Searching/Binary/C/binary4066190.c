#include<stdio.h>

int binarySearch(int[],int,int);

int main(){
  int i,n,q,key,count=0,s[100000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySearch(s,n,key)!=0)count++;
  }

  printf("%d\n",count);

  return 0;
}

int binarySearch(int a[],int x,int y){
  int l=0,r=x,m;

  while(l<r){
    m = (l+r)/2;
    if(a[m]==y) return 1;
    if(a[m]>y) r=m;
    else if(a[m]<y) l=m+1;
  }
  return 0;
}

