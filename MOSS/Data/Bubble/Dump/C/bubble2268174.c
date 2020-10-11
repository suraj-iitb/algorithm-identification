#include <stdio.h>
#define Max 100

int main(){
  int A[Max];
  int n,i,temp,flag=0;
  int time=0;
  
  scanf("%d",&n);
  for(i=0 ; i<n ; i++) scanf("%d",&A[i]);

  while(flag < n-1){
    for(i=n-1 ; i>=1+flag ; i--){
      if(A[i] < A[i-1]){
        temp = A[i];
        A[i] = A[i-1];
        A[i-1] = temp;
	time++;
      }
    }
    flag++;
  }

  for(i=0 ; i<n-1 ; i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",time);

  return 0;
}
