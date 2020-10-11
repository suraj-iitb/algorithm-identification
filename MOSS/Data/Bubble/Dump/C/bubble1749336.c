#include <stdio.h>

#define N 100

int main() {
  int flag,num,i,j,A[N],kari,count=0;

  scanf("%d",&num);
  for(i=0; i<num; i++){
    scanf("%d",&A[i]);
  }
  flag = 1;
 
  for(i=0; flag==1; i++){
    flag = 0;
    for(j=num-1; j>=i+1; j--){
      if(A[j] < A[j-1]){
	kari = A[j];
	A[j] = A[j-1];
	A[j-1] = kari;
	flag = 1;
	count++;
      }
    }
  }
  for(i=0; i<num-1; i++)    printf("%d ",A[i]);
  printf("%d\n",A[num-1]);
  printf("%d\n",count);

  return 0;
}
