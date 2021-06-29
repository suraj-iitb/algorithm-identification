#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int count=0;
void Merge(int*,int,int,int);
void MergeSort(int*,int,int);
int main(){
  int n,i;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  MergeSort(A,0,n);
  
    
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

void Merge(int *a,int l,int m,int r){
  int n1,n2,i,j,k;
  int *L,*R;
  n1=m - l;
  n2=r - m;
  L=(int *)malloc((n1+1) * sizeof(int));
  R=(int *)malloc((n2+1) * sizeof(int));
  for(i=0;i<n1;i++){
    L[i]=a[l+i];
  }
 
  for(i=0;i<n2;i++){
    R[i]=a[m+i];
   
  }
 
  L[n1]=INFINITY;
  R[n2]=INFINITY;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    if(L[i]<R[j]){
      a[k] = L[i];
      i=i+1;
    }
    else{
      a[k] = R[j];
      j=j+1;
    }
    count++; }
  free(R);
  free(L);
  
}


void MergeSort(int*a,int l,int r){
  int m;
  if(l+1<r){
    m = (l+r)/2;
   
    MergeSort(a,l,m);
    MergeSort(a,m,r);
    Merge(a,l,m,r);
  }
}

