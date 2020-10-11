#include <stdio.h>
#define stn 200000000;
typedef struct{
  char mk;
  int num;
}C;
void merge(C A[],int n,int left,int mid,int right);
void mergeSort(C A[],int n,int left,int right);
int partition(C A[],int n,int p,int r);
void quickSort(C A[],int n,int p,int r);
int isStable(C in[],C out[]);
C L[50000],R[50000];
int n;

int main(){

  int i;
  C A[100001],A2[100001];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].mk,&A[i].num);
    A2[i]=A[i];
  }
  
  mergeSort(A,n,0,n);
  quickSort(A2,n,0,n-1);
  
  if(isStable(A,A2)) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++) printf("%c %d\n",A2[i].mk,A2[i].num);
  
  return 0;
}

int partition(C A[],int n,int p,int r)
{
  int i,j;
  C x,temp;
  
  x = A[r];
  i = p-1;
  for(j=p;j<r;j++){
    if(A[j].num<=x.num){
      i=i+1;
      temp=A[i];
      A[i]=A[j];
      A[j]=temp;
    }
  }
  temp=A[i+1];
  A[i+1]=A[r];
  A[r]=temp;

  return i+1;

}

void quickSort(C A[],int n,int p,int r)
{
  int q;
  
  if(p<r){
    q=partition(A,n,p,r);
    quickSort(A,n,p,q-1);
    quickSort(A,n,q+1,r);
  }
}
 
void merge(C A[],int n,int left,int mid,int right)
{
  int i,j=0,k;  
  int n1=mid-left;
  int n2=right-mid;
 
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1].num=R[n2].num=stn;
  i=0;
  for(k=left;k<right;k++){
    if(L[i].num<=R[j].num){
      A[k]=L[i++];
    }
    else A[k]=R[j++];
  }
}
 
void mergeSort(C A[],int n,int left,int right)
{
  int mid;
 
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

int isStable(C A[],C A2[])
{
  int i;
  
  for(i=0;i<n;i++){
    if( A[i].num != A2[i].num || A[i].mk != A2[i].mk )
      return 0;
  }

  return 1;
}
