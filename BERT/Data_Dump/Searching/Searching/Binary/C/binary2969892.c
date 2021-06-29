#include<stdio.h>
int binarysearch(int );

int a[1000000],n;

int main(){
  int i,q,t,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(binarysearch(t)) count++;
  }

  printf("%d\n",count);

  return 0;
}

int binarysearch(int k){
  int l=0;
  int m;
  int r=n;

  while(l<r){
    m=(l+r)/2;
    if(k==a[m]) return 1;
    if(k>a[m]) l=m+1;
    else if(k<a[m]) r=m;
  }
  return 0;
}

