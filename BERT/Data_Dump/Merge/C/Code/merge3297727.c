#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 999999999
#define N 500000

void Merge(int *,int,int,int);
void Mergesort(int *,int,int);

int calc;
int main(){
  int n,a[N],i;
  calc=0;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }
  Mergesort(a,0,n);
  for(i=0; i<n-1; i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",calc);
  
  return 0;
}

void Merge(int *a,int left,int mid,int right){
  int n1,n2,L[N],R[N],i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0; i<n1; i++) L[i]=a[left+i];
  for(i=0; i<n2; i++) R[i]=a[ mid+i];
  L[n1]=MAX;
  R[n2]=MAX;
  i=j=0;
  for(k=left; k<right; k++){
    calc++;
    if(L[i]<=R[j]){
      a[k]=L[i];
      i++;
    }else{
      a[k]=R[j];
      j++;
    }
  }
}

void Mergesort(int *a,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    Mergesort(a,left,mid  );
    Mergesort(a, mid,right);
    Merge(a,left,mid,right);
  }
}

