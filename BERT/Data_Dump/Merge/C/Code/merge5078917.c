#include <stdio.h>
#define N 1000000001

int s[N],cnt=0;

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int main(){
  int i,n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  mergesort(s,0,n);
  for(i=0;i<n;i++){
    if(i>=1) printf(" ");
    printf("%d",s[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

void merge(int *a,int left,int mid,int right){
  int i,j,k,n1,n2;
  n1=mid-left;
  n2=right-mid;
  int L[n1],R[n2];
  //printf("L: ");
  for(i=0;i<n1;i++){
    L[i]=a[left+i];
    //printf("%d ",L[i]);
  }
  //printf("\n");
  //printf("R: ");
  for(i=0;i<n2;i++){
    R[i]=a[mid+i];
    //printf("%d ",R[i]);
  }
  //printf("\n");
  L[n1]=N;
  R[n2]=N;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      a[k]=L[i];
      i++;
    }
    else{
      a[k]=R[j];
      j++;
    }
  }
}

void mergesort(int *a,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid,right);
    merge(a,left,mid,right);
  }
}
