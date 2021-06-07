#include<stdio.h>
#define N 1000000

int A[N],n;

int binarySearch(int key){
  int left=0;
  int right=n;
  int center;

  while(left<right){
    center=(left+right)/2;
    if(key==A[center])return 1;
    if(key>A[center])left=center+1;
    else if(key<A[center])right=center;
  }
  return 0;
}


int main(){
  int i,j,k,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  scanf("%d",&j);
for(i=0;i<j;i++){
 scanf("%d",&k);
 if( binarySearch(k))sum++;
  }

 printf("%d\n",sum);
  return 0;
}
