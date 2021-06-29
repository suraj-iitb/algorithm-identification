#include<stdio.h>
#include<stdlib.h>

int binarySearch(int*,int,int);

int main(){
  int i,j,n,q,*S,*T;

  scanf("%d",&n);
  if(n > 100000)exit(1);
  S = malloc((n+1) * sizeof(int));
  for(i=0;i < n;i++){
    scanf("%d",&S[i]);
    if(S[i] < 0)exit(2);
  }
  scanf("%d",&q);
  if(q > 50000)exit(3);
  T = malloc(q * sizeof(int));
  for(i=0;i < q;i++){
    scanf("%d",&T[i]);
    if(T[i] < 0)exit(4);
    for(j=0;j < i;j++){
      if(T[j] == T[i])exit(5);
    }
  }
  j = 0;
  for(i=0;i < q;i++){
    if(binarySearch(S,T[i],n))j++;
  }
  printf("%d\n",j);
  return 0;  
}

int binarySearch(int *S,int t,int n){
  int mid,left = 0,right = n;
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == t)return 1;
    else if(t < S[mid])right = mid;
    else left = mid + 1;
  }
  return 0;
}

