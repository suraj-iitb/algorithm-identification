#include<stdio.h>
#include<string.h>
   
int main(){
  int S[100000];
  int T[50000];
  int n,i,q,j,count=0,left,right,mid;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  for(i = 0; i < q; i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(T[i] == S[mid]){
	count++;
	break;
      }
      if(T[i] > S[mid]){
	left = mid + 1;
      }else if(T[i] < S[mid]){
	right = mid;
      }
    } 
  }
  
  printf("%d\n",count);
  return 0;
}
