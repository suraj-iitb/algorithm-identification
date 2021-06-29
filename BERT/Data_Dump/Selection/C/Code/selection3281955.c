#include <stdio.h>
int main(){
  int i,j,minj,N,A[100],temp,count=0,flag;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  for(i=0;i<N;i++){
    minj = i;//minj最小値が入っている要素番号(iと仮定)                          
    flag=1;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
        minj=j;//最小値の要素番号をminjに格納                                   
        flag=0;
      }
      if(j==N-1&&flag==1)count--;
    }
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    count++;
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i==N-1){
      printf("\n");
      break;
    }
    printf(" ");
  }
  printf("%d\n",count);
  return 0;
}







