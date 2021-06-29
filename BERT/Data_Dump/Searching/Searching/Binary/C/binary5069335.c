#include <stdio.h>
#include <stdlib.h>

int binarySearch (int);
int n,q,*S,*T;
int main(){
  int i,key,count=0;
  
  scanf("%d",&n);
  S=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

   scanf("%d",&q);
  T=(int *)malloc(sizeof(int)*n);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    key=T[i];
    if(binarySearch(key)==1)count++;
  }
  printf("%d\n",count);

  return 0;
}

int binarySearch(int key){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left + right) / 2;
    if (S[mid] == key)
      return 1;
    else if (key < S[mid])
      right = mid;
    else 
      left = mid + 1;
  }
  return 0;
}

