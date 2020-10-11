#include<stdio.h>
#define N 500001
int n,count;
void merge(int a[],int left,int mid,int right){
    int n1,n2,i,j,k;
    n1=mid-left;
    n2=right-mid;
    int l[n1+1],r[n2+1];
    for(i=0;i<n1;++i) l[i]=a[left+i];
    for(i=0;i<n2;++i) r[i]=a[mid+i];
    l[n1]=r[n2]=2000000000;
    i=j=0;
    for(k=left;k<right;k++){
        count++;
        if(l[i]<=r[j])a[k]=l[i++];
        else a[k]=r[j++];
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
int main()
{
  int i;
  int A[N];
 
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
