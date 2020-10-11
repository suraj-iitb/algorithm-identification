#include<stdio.h>

#define Max 100
#define Min 1
#define AMAX 100

int main(){
  int i,n,A[AMAX],flag=1,tmp,cnt=0;

  scanf("%d",&n);

  if(n >= Min && n <= Max)
    for(i=0; i<n; i++)
      scanf("%d",&A[i]);

  while(flag){
    flag=0;
    for(i=n-1; i>=1; i--){
      if(A[i] < A[i-1]){
	tmp = A[i];
	A[i] = A[i-1];
	A[i-1] = tmp;
	cnt++;
	flag = 1;
      }
    }
  }

  for(i=0; i<n; i++)
    if(i == n-1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);

  printf("%d\n",cnt);

  return 0;
}
	

  

