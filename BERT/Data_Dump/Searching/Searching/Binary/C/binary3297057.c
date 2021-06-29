#include <stdio.h>
int A[1000000],a;
int search(int key);
int main(){
  int i,j,k,sum=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%d",&k);
    if(search(k)){
      sum++;
    }
  }
  printf("%d\n",sum);
  return 0;
}
int search(int key){
  int l=0;
  int r=a;
  int mid;
  while(l<r){
    mid=(l+r)/2;
    if(key==A[mid]){
      return 1;
    }
    if(key>A[mid]){
      l=mid+1;
    }
    else if (key<A[mid]){
	r=mid;
    }
  }
  return 0;
}

