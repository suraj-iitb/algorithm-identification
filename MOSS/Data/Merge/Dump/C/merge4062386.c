#include <stdio.h>

int n;
int A[500020],count=0;
int S[500020];

void mergeSort(int A[],int,int);
void mergeSort(int A[],int,int);

int main(){
  int left=0,right,i;
  
  scanf("%d",&n);
    right=n;
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }

    mergeSort(A,left,right);
    for(i=0;i<n;i++){
      if(i==n-1)
	printf("%d\n",A[i]);
      else
	printf("%d ",A[i]);
    }

    printf("%d\n",count);
    return 0;
}

void merge(int A[],int left,int mid,int right)
{
  int n1,n2,i,j,k;
  int L[500120],R[500120];
  n1 =mid-left;
  n2 =right-mid;
 
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(j=0;j<n2;j++){
    R[j]=A[mid+j];
  }
  L[n1]=1000000000;
  R[n2]=1000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      if(L[i]<=R[j]){
       	A[k]=L[i];
	i++;
	count++;
      }
      else{
	A[k]=R[j];
	j++;
	count++;
      }
      
    }
}

void mergeSort(int A[],int left,int right)
{
  int mid;
  if(left+1<right){
    mid =(left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

