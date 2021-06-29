#include <stdio.h>

int bubbleSort(int A[],int N){
  int j,temp;
  int count = 0;
   int flag = 1;
 int i =0;

 while(flag){
   flag=0;

    for(j=N-1;j>=1+i;j--){
      if(A[j]<A[j-1]){
        temp=A[j-1];
    A[j-1]=A[j];
    A[j]=temp;
    flag=1;
    count++;
      }

    }
 }
return count;
}

int main(){
  int A[100],N,i,count;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
    count = bubbleSort(A,N);

    for(i=0;i<N;i++){
      if(i>0)printf(" ");
      printf("%d",A[i]);
    }

    printf("\n");
    printf("%d",count);
    printf("\n");

    return 0;


}


