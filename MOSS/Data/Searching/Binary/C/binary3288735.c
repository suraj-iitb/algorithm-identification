#include<stdio.h>

int A[1000000],n;
int BinarySearch(int);

int main(){
  int i,b,c,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&c);
    if(BinarySearch(c))sum++;
  }
  printf("%d\n",sum);

  return 0;
}
int BinarySearch(int x){
  int left=0;
  int right=n;
  int mid;

  while(left < right){
    mid=(left + right)/2;
    if(x==A[mid])return 1;
    if(x > A[mid])left=mid+1;
    else if(x<A[mid])right=mid;
  }
  return 0;
}

