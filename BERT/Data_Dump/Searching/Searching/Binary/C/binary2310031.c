#include<stdio.h>

int binarySearch(int*,int,int);

int main(){
  int n,q,i,j;
  int s[100000],t,f=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(binarySearch(s,t,n))f++;
  }
  
  printf("%d\n",f);
  
  return 0;
}

int binarySearch(int A[],int t,int n){
  int i;
  int l = 0, r = n, mid;

  while(l<r){
    mid = (l + r)/2;
    if(A[mid] == t)return 1;
    else if(t < A[mid])r = mid;
    else l = mid + 1;
  }
 
  return 0; 
}
