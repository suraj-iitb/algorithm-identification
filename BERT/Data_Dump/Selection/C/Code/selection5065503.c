#include <stdio.h>
#define NUM 100
int selectionSort(int A[], int N){
  int i,j,minj,temp;
  int count = 0;

  for(i=0;i<N-1;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])
         minj = j;
    }
    temp=A[i];
   A[i]=A[minj];
   A[minj]=temp;


  if(A[i]!=A[minj])
    count++;
  }
  return count;
}


int main(){
  int A[NUM],N,count,i;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);}
  count = selectionSort(A,N);//変更後の数列                                                         

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }

  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
}

