#include<stdio.h>
#define M 500000
int a[M],b[M],count=0;
void mergeSort(int *a,int l,int r){
  int i,j,k,m;
  if(r>l){
    m=(r+l)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    for(i=m+1;i>l;i--)
      b[i-1]=a[i-1];
    for(j=m;j<r;j++)
      b[r+m-j]=a[j+1];
    for(k=l;k<=r;k++){
      a[k]=(b[i]<b[j])?b[i++]:b[j--];
      count++;
    }
  }
}

main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  mergeSort(a,0,n-1);
  for(i=0;i<n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[n-1],count);
  return 0;
}
