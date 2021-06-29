#include <stdio.h>

#define MAX 500000
#define INFTY 1000000000

void marge(int,int,int);
void margeSort(int,int);

int arr[MAX],n,count=0;

int main(){

  int i,left=0,right;
  
  //in
  scanf("%d",&n);
  
  right = n;
  
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  //sort
  margeSort(left,right);
  
  //out
  for(i=0;i<n;i++){
    if(i<n-1) printf("%d ",arr[i]);
    else printf("%d\n",arr[i]);
  }
  printf("%d\n",count);

  return 0;
}

void marge(int left,int mid,int right){
  int i,j,k,n1,n2,l[MAX],r[MAX];
  
  n1 = mid - left;
  n2 = right - mid;
  
  for(i=0;i<n1;i++){
    l[i]=arr[left+i];
  }
  
  for(i=0;i<n2;i++){
    r[i]=arr[mid+i];
  }
  
  l[n1] = INFTY;
  r[n2] = INFTY;
  
  i = j = 0;
  
  for(k=left;k<right;k++){
    if(l[i]<=r[j]){
      arr[k]=l[i];
      i++;
    }else{
      arr[k]=r[j];
      j++;
    }
    count++;
  }
}

void margeSort(int left,int right){
  int mid;
  
  if(left+1 < right){
    mid=(left+right)/2;
    margeSort(left,mid);
    margeSort(mid,right);
    marge(left,mid,right);
  }
}
