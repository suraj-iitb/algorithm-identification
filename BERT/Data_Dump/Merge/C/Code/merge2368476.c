#include<stdio.h>
#include<stdlib.h>
#define Max 1000000000
#define N 500000
void merge1(int *,int,int,int);
void merge2(int *,int,int);
int cnt=0;
int main()
{
  int n,S[N];
  int i;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  
  merge2(S,0,n);

  for(i=0; i<n; i++){
    printf("%d",S[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",cnt);
  
  return 0;
}

void merge1(int A[],int left,int mid,int right)
{
  int n1,n2;
  int i,j,k;
  int *R,*L;
  
  n1 = mid -left;
  n2 = right - mid;
  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));

  for(i=0; i<=n1-1; i++){
    L[i] = A[left+i];
  }
  
  for(i=0; i<=n2-1; i++){
    R[i] = A[mid+i];
  }
  i = 0;
  j = 0;
  R[n2]=Max;
  L[n1]=Max;
  
  for(k=left; k<=right-1; k++){
    if(L[i]<=R[j]){
      A[k] = L[i];
      i = i + 1;
      cnt++;
    }
    else{
      A[k] = R[j];
      j = j + 1;
      cnt++;
    }
  }
  free(R);
  free(L);
}

void merge2(int A[],int left,int right)
{
  int i,mid;
  if(left+1<right){
    mid = (left+right) / 2;
    merge2(A,left,mid);
    merge2(A,mid,right);
    merge1(A,left,mid,right);
  }
}

    
		      
  
  
  
