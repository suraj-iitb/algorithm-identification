#include<stdio.h>
#include<stdlib.h>
#define INFTY 2147483647;
int count=0;
void merge(int *A,int l,int m,int r){
  int *L,*R,i,j,k;
  int n1=m-l;
  int n2=r-m;

  L=(int *)malloc((n1+1)*sizeof(int));
  R=(int *)malloc((n2+1)*sizeof(int));
  for(i=0;i<n1;i++){
    L[i]=A[l+i];
  }
  for(j=0;j<n2;j++){
    R[j]=A[m+j];
  }
  
  L[n1]=R[n2]=INFTY;
  i=j=0;
  for(k=l;k<r;k++){
   
      count++;
    if(L[i]<R[j])
      {A[k]=L[i];i++;}
    else{ A[k]=R[j];j++;}
 
  }
  free(L);free(R);
}
void mergeSort(int *A,int l,int r){
  if(l+1< r){
    int m=(l+r)/2;
    mergeSort(A,l,m); 
    mergeSort(A,m,r);
    merge(A,l,m,r);
  }
  }

int main(){
    int i,j,n,A[500000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }
    
    mergeSort(A,0,n);
    for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i !=n-1)printf(" ");
    }
    printf("\n%d\n",count);
    return 0;
  }

