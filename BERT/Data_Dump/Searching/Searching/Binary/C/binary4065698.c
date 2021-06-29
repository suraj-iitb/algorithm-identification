#include <stdio.h>


int A[1000000],n;

//二分探索
int binarysearch(int k){
  int left=0;
  int mid;
  int right=n;

  while(left<right){
    mid=(left+right)/2;
    if(k==A[mid]) return 1;
    if(k<A[mid]) right=mid;
    else if(k>A[mid])left=mid+1;
  }
  return 0;

}

int main(){
  int i,p,keynumber,sum=0;

  //探索される数列Sを決定
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  //探索する数列Tを決定
  scanf("%d",&p);
  for(i=0;i<p;i++){
    scanf("%d",&keynumber);
    if(binarysearch(keynumber)) sum++;
  }

  printf("%d\n",sum);

  return 0;
}

