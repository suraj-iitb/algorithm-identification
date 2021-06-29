#include<stdio.h>
int count=0;
void selectionSort(int*,int);
int main(){
  int n,a[100],i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  selectionSort(a,n);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",count);
  return 0;

}
void selectionSort(int* A,int N){
  int i,j,minj,x;// N個の要素を含む0-オリジンの配列A
  for(i=0;i<=N-1;i++){
    minj = i;
    for( j=i;j<=N-1;j++){
      if (A[j] < A[minj]){
	minj = j;
      }
    }
    if(minj!=i){
	x=A[i];
	A[i]=A[minj];
	A[minj]=x;
	count++;
    }
  }
}

