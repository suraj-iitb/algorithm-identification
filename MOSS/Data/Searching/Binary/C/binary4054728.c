#include <stdio.h>
#define TRUE 1
#define FALSE 0


int binarySearch(int A[],int key,int n){
  int right = n;
  int left =0;
  int mid;

  while(left < right){
    mid = (left + right)/2;
    
    if(key == A[mid]) return TRUE;

    if(key > A[mid])
      left = mid+1;  
    

    if(key < A[mid])
      right = mid;
  }

  return FALSE;
  
}

int main(){
  int n,q,i,t;
  int s[100001];
  int cnt=0;

  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&s[i]);

  scanf("%d",&q);
  
  for(i=0; i<q; i++){
    scanf("%d",&t);
    if(binarySearch(s,t,n) == TRUE) cnt++;
  }

  printf("%d\n",cnt);

  return 0;
  
}

