#include <stdio.h>
#define N 500000
#define P 250000
#define SENTINEL 1000000000
int s[N];
long count;

void MergeSort(int *,int,int);
void Merge(int *,int,int,int);

main(){
  long n,i,left,right;

  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&s[i]);

 
  left=0;
  right=n;

  MergeSort(s,left,right);

  for(i=0; i<n-1; i++)
    printf("%d ",s[i]);
  printf("%d\n%d\n",s[n-1],count);
  return 0;

}


void MergeSort(int *s, int left, int right){
  long mid;
  if(left+1<right){
    mid=(left+right)/2;
    MergeSort(s,left,mid);
    MergeSort(s,mid,right);
    Merge(s,left,mid,right);
  }
}
  
void Merge(int *s, int left, int mid, int right){
  long n1,n2,i,j,k;
  
  n1=mid-left;
  n2=right-mid;

  int l[n1+1],r[n2+1];

  for(i=0; i<n1; i++)
    l[i]=s[left+i];

  for(i=0; i<n2; i++)
    r[i]=s[mid+i];
  
  l[n1]=SENTINEL;
  r[n2]=SENTINEL;
  
  i=0;
  j=0;
  
  for(k=left; k<right; k++){
    if(l[i]<=r[j]){
      s[k]=l[i];
      i++;
    }
    else {
      s[k]=r[j];
      j++;
    }
    count++;
  }
}
