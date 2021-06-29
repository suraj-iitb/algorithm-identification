#include<stdio.h>
#define N 100
void insertionSort(int *,int);
int main()
{
  int a,b[N],i;
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&b[i]);
       
    }
    for(i=0;i<a-1;i++)
      printf("%d ",b[i]);
    printf("%d\n",b[a-1]);
    insertionSort(b,a);
    return 0;
}
void insertionSort(int *A,int B){
  int i,v,j,k;
  for(i=1;i<B;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]= A[j];
      j--;
    }
    A[j+1] = v;
    for(k=0;k<B-1;k++)
      printf("%d ", A[k]);
    printf("%d\n", A[B-1]);
  }
}
    

