#include<stdio.h>
 
#define INFTY 2000000000
#define MAX 500000
 
int count=0;
void merge(int *S,int left,int mid,int right){
 
  int L[MAX/2+2],R[MAX+2];
  int i,j,k;
  int n1,n2;
  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<n1;i++)
    L[i]=S[left+i];
   
  for(i=0;i<n2;i++)
    R[i]=S[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      S[k]=L[i];
    i+=1;
    }
    else{
      S[k]=R[j];
      j+=1;
    }
  }
}
 
void mergeSort(int *S,int left,int right){
  int mid;
 
  if(left+1< right){
    mid = (left+right)/2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}
     
 
int main(){
 
  int S[MAX];
  int n,i;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
   
  mergeSort(S,0,n);
 
  for(i=0;i<n;i++){
    if(i){
      printf(" ");
    }
    printf("%d",S[i]);
  }
  printf("\n%d\n",count);
   
  return 0;
}
