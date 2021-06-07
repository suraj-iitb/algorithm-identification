#include <stdio.h>

int a[100000],n;

int binarySearch(int key){
  int left=0, right=n, mid;

  while(left<right){
    mid=(left+right)/2;
    
    if(a[mid]==key)
      return 1;
    else if(key<a[mid])
      right=mid;
    else
      left=mid+1;
  }
  return -1;
}

int main(){
  int count=0,i,q,b;

  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&b);
    if(binarySearch(b)==1)
      count++;
  }

  printf("%d\n",count);

  return 0;
}

