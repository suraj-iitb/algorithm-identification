#include<stdio.h>
#include<stdlib.h>

void maerge(int *,int,int,int,int);
void mergeSort(int *,int,int);

int result=0;

int main(){
  int n,*A;
  int i;
  
  scanf("%d",&n);
  A=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);

	 
  mergeSort(A,0,n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",result);

  free(A);
  
  return 0;
}

void merge(int *A,int l,int m,int r){
  int n1,n2;
  int *L,*R;
  int i,j,k;
  n1=m-l;
  n2=r-m;
  L=(int *)malloc((n1+1)*sizeof(int));
  for(i=0;i<n1;i++) L[i]=A[l+i];
  R=(int *)malloc((n2+1)*sizeof(int));
  for(i=0;i<n2;i++) R[i]=A[m+i];
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    if(L[i]<=R[j])  A[k]=L[i++];
    else A[k]=R[j++];
    result++;
  }

  
  free(L);
  free(R);
}

void mergeSort(int *A,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergeSort(A,l,m);
    mergeSort(A,m,r);
    merge(A,l,m,r);
  }    
}

