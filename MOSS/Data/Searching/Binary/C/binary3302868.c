#include <stdio.h>
#define N 100000
#define Q 50000
#define NOT_FOUND -1


int count=0,n;

int binary(int a[],int key){
  int left=0,right=n,mid;

  while(left<right){
    mid=(left+right)/2;
    if(a[mid]==key)return mid;
    else if(key<a[mid])right=mid;
    else left=mid+1;
  }
  return NOT_FOUND;
}




int main(){
  int a[N],b[Q],i,q;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<q;i++)
    if(binary(a,b[i])!=NOT_FOUND)count++;
  
  printf("%d\n",count);
  return 0;
}



