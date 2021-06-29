#include<stdio.h>
int SelectionSort(int A[],int N){
  int i,j,temp,cnt=0,mini;
  for(i=0;i<N-1;i++){
    mini=i;
    for(j=i;j<N;j++){
      if(A[j]<A[mini]) mini=j;
    }
    temp = A[i];
    A[i]=A[mini];
    A[mini] = temp;
    if(i != mini) cnt++;
  }
  return cnt;
}
int main(){
  int A[100],N,i,j,cnt;
  scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    cnt = SelectionSort(A,N);

    for(i=0;i<N;i++){
      if(i>0) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n%d\n",cnt);
      return 0;
}

