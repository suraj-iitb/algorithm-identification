#include<stdio.h>
#define S 2000000000
#define Max 500000
void merge(int *A,int n,int left, int mid ,int right);
void mergesort(int *A,int n,int left ,int right);
int Left[Max/2+2];
int Right[Max+2];
int count;

int main(){
  int A[Max],num,i;
  count=0;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
mergesort(A,num,0,num);
  for(i=0;i<num;i++){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}
void merge(int A[],int n,int left,int mid,int right){
  int A1=mid-left;
  int A2=right-mid;
  int i,j,m;
  for(i=0;i<A1;i++)Left[i] = A[left+i];
  for(i=0;i<A2;i++)Right[i]=A[mid+i];
  Left[A1]=S;
  Right[A2]=S;
  i=0;
  j=0;
  for(m=left;m<right;m++){
    count++;
    if(Left[i]<=Right[j]){
      A[m]=Left[i++];
    }else{
      A[m]=Right[j++];
    }
  }
}
void mergesort(int A[],int n,int left,int right){
  int mid;
  if(left+1 <right){
    mid = (left+right)/2;
    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}
