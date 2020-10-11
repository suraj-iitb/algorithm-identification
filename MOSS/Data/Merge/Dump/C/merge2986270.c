#include<stdio.h>
void merge(int[],int,int,int,int);
void mergeSort(int[],int,int,int);
#define MAX 500000
int Right[MAX/2+2],Left[MAX/2+2];
int count;
int main(){
  int data[MAX],n,i,key;
  count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&data[i]);
  mergeSort(data,n,0,n);

  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",data[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

void mergeSort(int data[],int n,int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(data,n,left,mid);
    mergeSort(data,n,mid,right);
    merge(data,n,left,mid,right);
  }
}

void merge(int data[],int n,int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  for(int i=0;i<n1;i++)Right[i]=data[left+i];
  for(int i=0;i<n2;i++)Left[i]=data[mid+i];
  Right[n1]=Left[n2]=1000000000;
  int i=0,j=0;
  for(int k=left;k<right;k++){
    count++;
    if(Left[i]<=Right[j])data[k]=Left[i++];
    else data[k]=Right[j++];
  }
}

