#include<stdio.h>

#define MAXA 100000
#define MAXT 50000
#define NOT_FOUND 0 

int n,q;
int A[MAXA],T[MAXT];

int i,j;
int C=0;

int binarySearch(){
  int left=0;
  int right=n;
  int mid;
  while(left<right){
    mid = (left+right)/2;

    if(A[mid]==T[j])return 1;
    else if(T[j] < A[mid])right=mid;
    else left=mid+1;
  }
  return NOT_FOUND;
}

int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  scanf("%d",&q);

  for(j=0;j<q;j++){
    
    scanf("%d",&T[j]);
	
    C+=binarySearch();
  }


  printf("%d\n",C);

  return 0;
}

