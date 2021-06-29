#include <stdio.h>

int main(){
  int n;
  int i,v,j,count;
  int A[100];

  scanf("%d",&n);
  
  for(i = 0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(count = 0;count<n;count++){
   	printf("%d",A[count]);
	if(count == n-1) break;
	printf(" ");
      }
  printf("\n");
  for(i = 1;i<=n-1;i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(count = 0;count<n;count++){
	printf("%d",A[count]);
	if(count == n-1) break;
	printf(" ");
      }
    printf("\n");
  }
}

