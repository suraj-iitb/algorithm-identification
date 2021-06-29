#include<stdio.h>

int N[1000000],n;

int binarySearch(int key){
  int left=0,right=n;
  int mid;
  while(left<right){
    mid=((left+right)/2);
    if(key==N[mid])return 1;
    if(key>N[mid])left=mid+1;
    else if(key<N[mid])right=mid;
}
  return 0;
}

int main(){
  int i,j,k,sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&N[i]);
  }
  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%d",&k);
    if(binarySearch(k))sum++;
  }
  printf("%d\n",sum);
  
  return 0;
}

