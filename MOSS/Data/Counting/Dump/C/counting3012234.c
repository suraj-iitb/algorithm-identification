#include<stdio.h>
#include<stdlib.h>
#define k 10001

void CountingSort(int A[],int B[],int n){
  int C[k+1];

 for(int i=0;i<=k;i++){
    C[i] = 0;
 }

 for(int j=0;j<n;j++){
    C[A[j]]++;
}

 for(int i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
 }

 for(int j=n-1;j>=0;j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
 }

}

int main(){
  int n;

  scanf("%d", &n);
 int A[n],B[n];
 for(int i=0;i<n;i++){
  scanf("%d",&A[i]);
}
  CountingSort(A,B,n);

 for(int j=0;j<n-1;j++){
	printf("%d ",B[j]);
}
printf("%d\n",B[n-1]);
return 0;
}
