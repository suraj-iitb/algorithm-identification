#include<stdio.h>
#include<stdlib.h>
#define N 500000
#define I 1000000000

int count=0;

void merge(int *,int,int,int);

void mergeSort(int *S,int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}


int main(){
  int n,i,*S,left=0;

  scanf("%d",&n);
  S=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++) scanf("%d",&S[i]);

  mergeSort(S,left,n);

  printf("%d",S[0]);
  for(i=1;i<n;i++) printf(" %d",S[i]);
  printf("\n");
  printf("%d\n",count);

  free(S);
  return 0;
}

void merge(int *S,int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i,j,k,L[n1],R[n2];
  /* L[0...n1], R[0...n2] を生成*/
  for(i=0;i<n1;i++) L[i] = S[left + i];
  for(i=0;i<n2;i++) R[i] = S[mid + i];
  L[n1] = I;
  R[n2] = I;
  i = 0;
  j = 0;
    for(k=left;k<right;k++){
      count++;
      if(L[i]<=R[j]){
	S[k] = L[i];
	i = i + 1;
      }else{ 
	S[k] = R[j];
	j = j + 1;
      }
    }
}

