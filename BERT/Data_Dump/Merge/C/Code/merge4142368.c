#include<stdio.h>
#define MAX 500000
#define INF 1000000001
int n,count,S[MAX];

void merge(int left,int right,int mid){
  int n1,n2,i,j,k,s1[MAX/2+2],s2[MAX/2+2];
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++) s1[i]=S[left+i];
  for(i=0;i<n2;i++) s2[i]=S[mid+i];
  i=j=0;
  s1[n1]=s2[n2]=INF;
  for(k=left;k<right;k++){
    count++;
      if(s1[i]>s2[j]) S[k]=s2[j++];
      else S[k]=s1[i++];
  }
}
void mergesort(int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(left,mid);
    mergesort(mid,right);
    merge(left,right,mid);
  }
}

int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);

  mergesort(0,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

