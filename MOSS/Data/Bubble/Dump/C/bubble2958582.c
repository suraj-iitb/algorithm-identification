#include<stdio.h>
void bubbleSort(int* ,int);
int count=0;
int main(){
  int n,a[100],i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  bubbleSort(a,n);
  for(i=0;i<n;i++) {
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
void bubbleSort(int *A, int N){ // N 個の要素を含む 0-オリジンの配列 A
    int flag = 1,j,x; // 逆の隣接要素が存在する
  while (flag){
    flag = 0;
    for(j=N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	x=A[j];
	A[j]=A[j-1];
	A[j-1]=x;
	count++;
	flag=1;
      } 
    }
  }
}

