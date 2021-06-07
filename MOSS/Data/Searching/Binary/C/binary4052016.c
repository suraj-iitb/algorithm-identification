#include <stdio.h>
#include <stdlib.h>

int A[100000],n;

int binarySearch(int key){
  int left = 0,right = n,mid;
  while (left < right){
    mid = (left + right) / 2;
    if (A[mid] == key)return 1;
    else if (key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}


int main(){
  int i,j,m,num=0,key;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  scanf("%d",&m);
  for(j=0;j<m;j++){
    scanf("%d",&key);
    if(binarySearch(key))num++;
  }
  printf("%d\n",num);

  return 0;
}
   

