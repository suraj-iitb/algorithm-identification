#include<stdio.h>
#define N 100

int main(){
  int A[N];
  int i,j,k,n,temp,flag,num;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  flag=1;

  while(flag==1){

    flag=0;

    for(j = n-1; j >= 1; j--){

      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;

	num++;
      }
      
    }//for

  }//while

  for(k = 0; k < n; k++){
    printf("%d",A[k]);
    if(k != n-1) printf(" ");
    else printf("\n");
  }

  printf("%d\n",num);

  return 0;

}

