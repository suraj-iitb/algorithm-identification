#include <stdio.h>
#define N 500000
#define INFTY 1000000000
void mergesort(int,int);
void merge(int,int,int);

int count=0,S[N];

int main(){
  int i,n;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergesort(0,n);
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1)  printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;

}
 

void merge(int left,int mid,int right){

  int x,y,L[N],R[N],i,j,k;

  x = mid - left;
  y = right - mid;

  for(i=0;i<x;i++){
    L[i]=S[left+i];
  }
  for(i=0;i<y;i++){
    R[i]=S[mid+i];
  }
  L[x]=INFTY;
  R[y]=INFTY;
  i=0;
  j=0;


  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      S[k]=L[i];
      i++;
    }
    else{
      S[k]=R[j];
      j++;
    }
    count++;
  }
}


void mergesort(int left,int right){
  int mid;
  if(left+1<right){
    mid = (left+right)/2;
    mergesort(left,mid);
    mergesort(mid,right);
    merge(left,mid,right);
  }
}
