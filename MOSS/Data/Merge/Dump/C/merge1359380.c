#include <stdio.h>
#define MAX 500000
#define SENTINEL 10000000000

void Merge(int[],int,int,int);
void MergeSort(int[],int,int);

int S[MAX],ct = 0;
int main(void){

  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  MergeSort(S,0,n);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",ct);

  return 0;
}
void Merge(int S[],int left,int mid,int right){
   
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int l[n1+1];
  int r[n2+1];
   
  for(i=0;i<n1;i++){
    l[i] = S[left+i];
  }
   
  for(i=0;i<n2;i++){
    r[i] = S[mid+i];
  }
  l[n1] = SENTINEL + 1;
  r[n2] = SENTINEL + 1;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(l[i]<=r[j]){
      S[k] = l[i];
      i += 1;
      ct++;
    } else{
      S[k] = r[j];
      j += 1;
      ct++;
    }
  } 
   
}
 
void MergeSort(int S[],int left,int right){
   
  int mid=0;
  if(left+1 < right){    
    mid=(left+right)/2;
    MergeSort(S,left,mid);
    MergeSort(S,mid,right);
    Merge(S,left,mid,right);  
  }
 
   
}
