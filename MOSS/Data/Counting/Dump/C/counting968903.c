#include<stdio.h>
int A[2000010];
void CouSort(int n){
  int k=10000,i,j,B[2000010],C[10010];
  for(i=0;i<k;i++)
    C[i]=0;
  for(j=0;j<n;j++){
    C[A[j]]++;
  }
  /* C[i]にはiの出現数が記録されている*/
  for(i=1;i<k;i++)
    C[i] = C[i] + C[i-1];
  /* C[i]にはi以下の数の出現数が記録されている*/
  for(j=n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i=1;i<n;i++)
    printf("%d ",B[i]);
  printf("%d\n",B[n]);
}

main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  CouSort(n);
  return 0;
}
