#include <stdio.h>
#define N 100

int main(){

  int i,count,num=0,s,j,tmp,k;
  int A[N];

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }


  for(k=0;k<num-1;k++){
    for(j=num-1;j>k;j--){
      if(A[j-1]>A[j]){
	tmp=A[j-1];
	A[j-1]=A[j];
	A[j]=tmp;
	count++;
      }
    }
  }
  for(s=0;s<num-1;s++){
    printf("%d ",A[s]);
  }
  printf("%d\n",A[num-1]);
  printf("%d\n",count);

  return 0;
}

