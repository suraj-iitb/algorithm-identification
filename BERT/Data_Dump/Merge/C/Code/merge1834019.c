#include <stdio.h>
 
#define N 500000
 
void merge(int*, int, int);
 
int a[N],n,count=0;
int temp[N];
 
 
int main(){
 
  int i,j;
 
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
 
    merge(a,0,n-1);
 
  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d",a[n-1]);
  printf("\n%d\n",count);
 
  return 0;
}
 
 
void merge(int x[],int left,int right){
 
  int mid,i,j,k;
 
  if(left>=right) return;
 
  mid=(left+right)/2;
 
  merge(x,left,mid);
  merge(x,(mid+1),right);
 
  for(i=left;i<=mid;i++){
    temp[i]=x[i];
  }
 
  for(i=(mid+1),j=right;i<=right;i++,j--){
    temp[i]=x[j];
  }
 
  i=left;
  j=right;
 
  for(k=left;k<=right;k++){
 
    if(temp[i]<=temp[j]) x[k]=temp[i++];
    else x[k]=temp[j--];
 
    count++;
}
 
}
