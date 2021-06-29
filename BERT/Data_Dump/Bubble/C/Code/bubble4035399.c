#include <stdio.h>
#define N 100
int main(){
  int i,j,n,A[N],flag = 1,temp,cunt = 0;
  scanf("%d",&n);
  for(i = 0; i < n;i++){
    scanf("%d",&A[i]);
  }
  
  while(flag){
    flag = 0;
    for(j = n-1;j > 0;j--){
      if (A[j] < A[j-1]){
	temp = A[j-1];
	A[j-1] = A[j];
	A[j] = temp;
	flag = 1;
	cunt++;
      }
    }
  }
for(i = 0;i < n;i++){
  if(i) printf(" ");
  printf("%d",A[i]);
      }
 printf("\n");
 printf("%d",cunt);
printf("\n");
return 0;
}

