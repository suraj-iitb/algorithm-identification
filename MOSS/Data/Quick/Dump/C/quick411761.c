/* C Quick Sort */

#include<stdio.h>
int n; /* 1<=n<=100000 */

int Partition(int A[], char M[], int p, int r);
void QuickSort(int A[], char M[], int p, int r);
void MergeSort(int A[], char M[], int l, int r);
void Merge(int A[], char M[], int l, int m, int r);

int main(){
  int i;
  int q;
  int stable_judge=0;

  scanf("%d%*c",&n);
  int A[n]; /* card number */
  char M[n];/* card mark */
  int A2[n];/* copy of A[n] */
  char M2[n];/* copy of M[n] */

  for(i=0;i<n;i++){
    scanf("%c%d%*c",&M[i],&A[i]);
  }
  /* copy */
  for(i=0;i<n;i++){
    A2[i]=A[i];
    M2[i]=M[i];
  }

  QuickSort(A, M, 0, n-1);
  MergeSort(A2, M2, 0, n); 
  
  for(i=0;i<n;i++){
    if(M[i]!=M2[i])stable_judge++;
  } 

  if(stable_judge>0){
    printf("Not stable\n");
  }else{
    printf("Stable\n");
  }

  for(i=0;i<n;i++){
    printf("%c %d\n",M[i],A[i]);
  }
  return 0;
}

int Partition(int A[], char M[], int p, int r){
  int i, j, x;
  int tempi;
  char tempc;

  x=A[r];
  i=p-1;
  for(j=p;j<=r-1;j++){
    if(A[j]<=x){
      i=i+1;
      tempi=A[i]; /* exchange */
      A[i]=A[j];
      A[j]=tempi;
      tempc=M[i];
      M[i]=M[j];
      M[j]=tempc;
    }
  }
  tempi=A[i+1]; /* exchange */
  A[i+1]=A[r];
  A[r]=tempi;
  tempc=M[i+1];
  M[i+1]=M[r];
  M[r]=tempc;
  return i+1;
}

void QuickSort(int A[], char M[], int p, int r){
  int q;
  if(p<r){
    q=Partition(A, M, p, r);
    QuickSort(A, M, p, q-1);
    QuickSort(A, M, q+1, r);
  }
}

void Merge(int A[], char M[], int l, int m, int r){
  int n1, n2, i, j, k;
  int L[500001], R[500001];
  char Lc[500001],Rc[500001];
  n1=m-l;
  n2=r-m;
  for(i=0; i<=n1-1; i++){
    L[i]=A[l+i];
    Lc[i]=M[l+i];
  }
  for(j=0;j<=n2-1;j++){
    R[j]=A[m+j];
    Rc[j]=M[m+j];
  }
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=l;k<=r-1;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      M[k]=Lc[i];
      i=i+1;
    }else{
      A[k]=R[j];
      M[k]=Rc[j];
      j=j+1;
    }
  }
}
 
void MergeSort(int A[], char M[], int l, int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    MergeSort(A, M, l, m);
    MergeSort(A, M, m, r);
    Merge(A, M, l, m, r);
  }
}
