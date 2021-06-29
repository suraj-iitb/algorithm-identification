#include<stdio.h>
#define MAX 500000
#define LASTNUM 1000000001

int le[MAX/2+2],ri[MAX/2+2];
int cnt;

void merge(int a[],int n,int left,int mid,int right){
  int i=0,j=0,k;
  int n1 = mid - left;
  int n2 = right - mid;
  for(i=0;i<n1;i++)le[i] = a[left + i];
  for(i=0;i<n2;i++)ri[i] = a[mid + i];
  le[n1] = ri[n2] = LASTNUM;
  i=0;
  for(k=left;k<right;k++){
    cnt++;
    if(le[i] <= ri[j]){
      a[k] = le[i++];
    }else{
      a[k] = ri[j++];
}
}
}

void mergesort(int a[],int n,int left,int right){
  if(left+1 < right){
    int mid = (left + right) / 2;
    mergesort(a,n,left,mid);
    mergesort(a,n,mid,right);
    merge(a,n,left,mid,right);
}
}

int main(){
  int a[MAX],n,i;
  cnt = 0; 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
  mergesort(a,n,0,n);
  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",a[i]);
}
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

