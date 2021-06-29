#include<stdio.h>
int S[1000000];
#define N 1e9
void merge(int *,int ,int ,int );
void mergeSort(int *,int ,int);
int cout;
int main(){
  int n;
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
    mergeSort(S,0,n);
    printf("%d",S[0]);
    for(i=1;i<n;i++){
      printf(" %d",S[i]);
    }
    printf("\n");
    printf("%d\n",cout);
    return 0;
}
void merge(int A[],int l,int m,int r){
  int n1=m-l,n2=r-m,i,j;
  int L[n1],R[n2];
  for(i=0;i<=n1-1;i++){
    L[i]=A[l+i];
  }
  for(j=0;j<=n2-1;j++){
    R[j]=A[m+j];
  }
  L[n1]=N;
  R[n2]=N;
  i=0;
  j=0;
  int k;
  for(k=l;k<=r-1;k++){
    cout++;
    if(L[i]<R[j]){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
      
    }

  }
}
void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

