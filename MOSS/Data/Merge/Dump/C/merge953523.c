#include <stdio.h>

#define N 500000

void Merge(int,int,int);
void Merge_Sort(int,int);

int S[N],c=0;
main(){
  int i,n;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  Merge_Sort(0,n);
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}

void Merge(int left,int mid,int right){
  int n1=mid-left,n2=right-mid,i,j,k;
  int L[n1],R[n2];

  for(i=0;i<n1;i++){
    L[i]=S[left+i];
  }

  for(i=0;i<n2;i++){
    R[i]=S[mid+i];
  }

  L[n1] = 1000000001;
  R[n2] = 1000000001;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      S[k]=L[i];
      i++;
    }
    else{
      S[k]=R[j];
      j++;
    }
    c++;
  }
}

void Merge_Sort(int left,int right){
  int mid;
  if (left+1<right){
    mid = (left + right)/2;
    Merge_Sort(left,mid);
    Merge_Sort(mid,right);
    Merge(left,mid,right);
  }
}
