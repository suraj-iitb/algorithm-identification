#include <stdio.h>
#include <stdlib.h>
#define INFTY 1000000001

void mergeSort(int *,int,int);
void merge(int *,int,int,int);
int c=0;

int main()
{
  int *S,n,i;

  scanf("%d",&n);
  
  S = (int *)malloc(n * sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1) printf(" ");
    else{
      printf("\n");
      printf("%d\n",c);
    }
  }

  free(S);

  return 0;
}

void mergeSort(int *S,int left,int right)
{
  int mid;
  
  if(left+1<right){
    mid = (left+right)/2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}

void merge(int *S,int left,int mid,int right)
{
  int n1,n2,k,i,j,*L,*R;
  n1 = mid-left;
  n2 = right-mid;

  L = (int *)malloc((n1+1) * sizeof(int));
  R = (int *)malloc((n2+1) * sizeof(int));
  
  for(i=0;i<n1;i++){
    L[i] = S[left+i];
  }

  for(i=0;i<n2;i++){
    R[i] = S[mid+i];
  }

  L[n1] = INFTY;
  R[n2] = INFTY;
  i=0,j=0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      S[k] = L[i];
      i++;
    }
    else{
      S[k] = R[j];
      j++;
    }
    c++;
  }

  free(L);
  free(R);
}

    
  

