#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int Left[MAX/2+2],Right[MAX/2+2];
int cnt;

void merge(int ary[],int n,int left,int mid,int right){
  int i,j,k;
  int n1,n2;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)Left[i]=ary[left+i];
  for(i=0;i<n2;i++)Right[i]=ary[mid+i];
  Left[n1]=Right[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(Left[i]<=Right[j]){
      ary[k]=Left[i++];
    }
    else{
      ary[k]=Right[j++];
    }
  }
}

void mergesort(int ary[],int n,int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergesort(ary,n,left,mid);
    mergesort(ary,n,mid,right);
    merge(ary,n,left,mid,right);
  }
}

int main(){
  int ary[MAX],n,i;
  cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ary[i]);
  }
  mergesort(ary,n,0,n);
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",ary[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}
		

