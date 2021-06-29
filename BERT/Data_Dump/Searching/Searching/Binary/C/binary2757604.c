#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 100000
#define pi M_PI

int main(){
  int n,q,k=0;
  int left,right,mid=0;
  int a[N],b[N];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
  }
  scanf("%d",&q);
  for(int j=0;j<q;j++){
      scanf("%d",&b[j]);
  }
  for(int j=0;j<q;j++){
      left=0;
  right=n;
      while(left<right){
          mid=(left+right)/2;
          if(a[mid]==b[j]){
              k++;
              break;
          }
            if(b[j]<a[mid]){
              right=mid;
          }else{
              left=mid+1;
          }
      }
  }
  printf("%d\n",k);
  return 0;
}

