#include <stdio.h>
#define MAX 500000
#define BIG 1000000000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count=0;
int main(){
 
int n,i;
int A[MAX];

scanf("%d",&n);
for(i=0;i<n;i++) scanf("%d",&A[i]);

mergeSort(A,0,n); 

for(i=0;i<n-1;i++) printf("%d ",A[i]);
printf("%d\n",A[n-1]);
printf("%d\n",count);

return 0;


}

void merge(int *A,int left,int mid,int right){
int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  int L[n1+1];
  int R[n2+1];
  
  for(i=0;i<=n1-1;i++){
    L[i]=A[left+i];
  }
  for(j=0;j<=n2-1;j++){
    R[j]=A[mid+j];
  }
  L[n1]=BIG;
  R[n2]=BIG;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
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


void mergeSort(int *A,int left,int right){

 int mid;
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

