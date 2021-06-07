#include<stdio.h>
#define N 100000
 
int binarySearch(int *,int,int);
int main(){   
  int i,n,q,S[N],T,c=0;
   
  scanf("%d",&n);
   
  for (i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
 
  scanf("%d",&q);
   
  for (i=0;i<q;i++){
    scanf("%d",&T);
    if (binarySearch(S,n,T)){
      c++;
    }
  }
   
  printf("%d\n",c);
  return 0;
}

int binarySearch(int S[],int n,int T){
    int left = 0;
    int right = n;
    int mid;
while(left < right){
  mid = (left + right) / 2;
  if(S[mid] == T) return mid;
  else if(T < S[mid]) right = mid;
  else left = mid + 1;
 }
  return 0;
}
