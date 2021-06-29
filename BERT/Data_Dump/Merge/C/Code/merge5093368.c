#include<stdio.h>
#define M 500000
int a[M],B[M],count=0;
void merge(int *a,int l,int r);

int main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  merge(a,0,n-1);
  for(i=0;i<n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[n-1],count);
  return 0;
}
void merge(int *a,int l,int r){
  int i,j,k,m,u;
  for(u=0; u < 1000; u++){
    B[u]=u;
  }
  if(r>l){
    m=(r+l)/2;
    merge(a,l,m);
    merge(a,m+1,r);
    for(i=m+1;i>l;i--)
      B[i-1]=a[i-1];
    for(j=m;j<r;j++)
      B[r+m-j]=a[j+1];
    for(k=l;k<=r;k++){
      a[k]=(B[i]<B[j])?B[i++]:B[j--];
      count++;
    }
  }
}

