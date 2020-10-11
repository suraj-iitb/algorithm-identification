#include<stdio.h>
#define INFINITY 1000000000

int A[500000];
int num=0;
int n1,n2;
int L[5000000/4];
int R[5000000/4];

void merge(int A[],int left,int mid,int right){
  int i,k,j;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=INFINITY;
  R[n2]=INFINITY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
num++;
    }
   else{
     num++;
  A[k]=R[j];
  j=j+1;
    }
  }
}
void mergesort(int A[],int left,int right){
  if(left+1<right){
    int mid;
    mid = (left + right)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main(){
  int n,i;
  scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&A[i]);
}
mergesort(A,0,n);
for(i=0;i<n;i++){
if(i==n-1){
printf("%d\n",(int)A[i]);
break;
}
printf("%d ",(int)A[i]);
}
printf("%d\n",num);

return 0;
}

