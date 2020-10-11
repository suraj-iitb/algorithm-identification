/* B Merge Sort */

#include<stdio.h>
/*#include<limits.h>*/
int n;  /* n <= 500000 */
void MergeSort(int A[], int l, int r);
void Merge(int A[], int l, int m, int r);
int counter=0;

int main(){

  int S[500001];  /* 0 <= an element in S <= 10^9 */
  int i;

  /*printf("int Max %d\n", INT_MAX);*/
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  MergeSort(S, 0, n);
  for(i=0;i<n-1;i++){
    printf("%d ", S[i]);
  }
  printf("%d\n", S[i]);

  printf("%d\n",counter);
  return 0;
}

void Merge(int A[], int l, int m, int r){
  int n1, n2, i, j, k;
  int L[500001], R[500001];
  n1=m-l;
  n2=r-m;
  for(i=0; i<=n1-1; i++){
    L[i]=A[l+i];
  }
  for(j=0;j<=n2-1;j++){
    R[j]=A[m+j];
  }
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=l;k<=r-1;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
      counter++;
    }else{
      A[k]=R[j];
      j=j+1;
      counter++;
    }
  }
}

void MergeSort(int A[], int l, int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    MergeSort(A, l, m);
    MergeSort(A, m, r);
    Merge(A, l, m, r);
  }
}
