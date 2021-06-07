#include <stdio.h>

#define N 100000
#define Q 50000

int main(){
  int S[N],T[Q];
  int n,m,i,count=0;
  int right,left,mid;

  scanf("%d",&n);
  for(i=0; i<n ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&m);
  for(i=0; i<m ; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<m; i++){
      left = 0;
      right = n;
      while(left < right){
	mid=(left + right)/2;
	if(T[i]==S[mid]){
	  count++;
	  break;
	}
	else if(T[i] > S[mid])
	  left = mid+1;
	else if(T[i] < S[mid])
	  right = mid;
      }
    }
  printf("%d\n",count);
  return 0;
}
