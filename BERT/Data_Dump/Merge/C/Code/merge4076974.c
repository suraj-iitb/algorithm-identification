#include<stdio.h>
#define N 500000
#define INF 1000000000
int n,count=0;
void merge(int a[],int left,int mid,int right);
void mergeSort(int a[],int left,int right);
int main()
{
  int i,A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  for(i=0;i<n;i++){
      if(i) printf(" ");
      printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}
void merge(int a[],int left,int mid,int right){
    int n1,n2,i,j,k;
    n1=mid-left;
    n2=right-mid;
     int L[n1+1],R[n2+1];
    for(i=0;i<n1;++i) 
    L[i]=a[left+i];
    for(i=0;i<n2;++i)
     R[i]=a[mid+i];
    L[n1]=INF;
    R[n2]=INF;
    i=0;j=0;
    for(k=left;k<right;k++){
        count++;
        if(L[i]<=R[j])
        a[k]=L[i++];
        else 
        a[k]=R[j++];
    }
}
void mergeSort(int a[],int left,int right){
    int mid;
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}
