#include <stdio.h>
#define N 500000

void MergeSort(int,int);
void Merge(int,int,int);
int S[N];
int cnt=0;

int main(){
  int i,n;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  MergeSort(0,n);

  for(i=0;i<n-1;i++){
    printf("%d",S[i]);
    if(i!=n-1)printf(" ");
  }

  printf("%d\n",S[n-1]);
  printf("%d\n",cnt);

  return 0;
}


void MergeSort(int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    MergeSort(left,mid);
    MergeSort(mid,right);
    Merge(left,mid,right);
  }
}


void Merge(int left,int mid,int right){
  int i,j,x;
  int L[mid-left+1], R[right-mid+1];

  for(i=0;i<mid-left;i++){
    L[i]=S[left+i];
  }
  for(i=0;i<right-mid;i++){
    R[i]=S[mid+i];
  }

  L[mid-left]=1000000000;
  R[right-mid]=1000000000;
  i=0;
  j=0;

  for(x=left;x<right;x++){
     cnt++;
    if (L[i]<=R[j]){
      S[x]=L[i];

      i=i+1;
    }
    else {
      S[x]=R[j];
      j=j+1;
    }   
  }
}
