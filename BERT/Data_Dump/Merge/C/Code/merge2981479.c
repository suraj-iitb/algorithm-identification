#include <stdio.h>
#define MAX 1000000001
void mergesort(int *,int ,int );
void merge(int *,int ,int ,int );
int count=0,n,Left[250001],Right[250001],i;

int main(void){
  int S[500000];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  mergesort(S,0,n);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
void mergesort(int *S,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(S,left,mid);
    mergesort(S,mid,right);
    merge(S,left,mid,right);
  }
}
void merge(int *S,int left,int mid,int right){
  int n1=mid-left,n2=right-mid,j,k;
  for(i=0;i<n1;i++)
    Left[i]=S[left+i];//not include mid
  for(i=0;i<n2;i++)
    Right[i]=S[mid+i];//include mid
  Left[n1]=MAX;
  Right[n2]=MAX;
  for(i=0,j=0,k=left;k<right;k++){
    if(Left[j]>Right[i])S[k]=Right[i++];
    else S[k]=Left[j++];
  }
  count+=right-left;
}
