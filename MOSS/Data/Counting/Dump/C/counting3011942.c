#include<stdio.h>
#define N 2000000
#define I 10000
int A[N],B[N],C[I];
void CountingSort(int A[],int k,int n){
  int i;
  int j;
  for(i=0;i<=k;i++){
    C[i]=0;
  }
 for(j=0;j<n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
for(j=n-1;j>=0;j--){
  B[C[A[j]]-1]=A[j];
  C[A[j]]--;
}
}
int main(){
int i,n,A_max=0;
scanf("%d",&n);
for(i=0;i<n;i++){
  scanf("%d",&A[i]);
  if(A_max<A[i])A_max=A[i];

}
CountingSort(A,A_max,n);
for(i=0;i<n;i++){
  if(i==(n-1))printf("%d",B[i]);
  else printf("%d ",B[i]);
}
printf("\n");

  return 0;
}

