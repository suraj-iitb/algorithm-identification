#include <stdio.h>

void selectionSort(int [],int);

int count=0;

int main(){
  int i,A[100],n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
selectionSort(A,n);

for(i=0;i<n;i++){
  if(i)printf(" ");
  printf("%d",A[i]);
  }
printf("\n");
printf("%d\n",count);

return 0;
}


void selectionSort(int A[],int N){
  int i,minj,j,t;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
  if(i!=minj){
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
    count++;
  }
 }
}
