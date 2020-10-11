#include <stdio.h>
#define N 100
int main(){

  int i,j,num;
  int minj,count=0;
  int A[N],tmp;

  scanf("%d",&num);
  
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }

 
  for(i=0;i<num;i++){
    minj=i;
    for(j=i;j<num;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(A[i]!=A[minj]){
      count++;
    }
    tmp=A[minj];
    A[minj]=A[i];
    A[i]=tmp;
     
  }


for(i=0;i<num-1;i++){
  printf("%d ",A[i]);
 }
printf("%d\n",A[num-1]);
printf("%d\n",count);



return 0;
}

