#include<stdio.h>
#include<math.h>

#define N 1000000
#define INFTY 2000000000

int A[N],c=0;

void Merge(int,int,int);
void MergeSort(int,int);

int main(){
  int i,m;

  scanf("%d",&m);

  for(i=0;i<m;i++)
  scanf("%d",&A[i]);

  MergeSort(0,m);

  for(i=0;i<m;i++){
    printf("%d",A[i]);
    if(i!=m-1)printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}
void Merge(int left,int mid,int right)
{
  int n1,n2,i,j,k,L[N],R[N];

  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<=n1-1;i++) 
    L[i] = A[left + i];
  
  for(i=0;i<=n2-1;i++)
    R[i] = A[mid + i];
      
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
      
  for (k=left;k<=right-1;k++)
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      c++;
    }
    else{
      A[k] = R[j];
      j = j + 1;
      c++;
    }
}
void  MergeSort(int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    MergeSort(left, mid);
    MergeSort(mid, right);
    Merge(left, mid, right);
  }
}
