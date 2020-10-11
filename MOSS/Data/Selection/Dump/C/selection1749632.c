#include<stdio.h>

SelectionSort(int A[],int N)
{
  int i,j,temp;
  int mini,cont=0;
  
  for(i=0;i<(N-1);i++){
    mini=i;
    for(j=i;j<N;j++){
      if(A[j]<A[mini])mini=j;
      }
      temp=A[i];
      A[i]=A[mini];
      A[mini]=temp;
      if(i != mini)cont++;
  }
  return cont;
}

int main(){
  
  int A[100],N,i;
  int cont;
  
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
 
  cont = SelectionSort(A,N);
  
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cont);
  
  return 0;
}
