#include <stdio.h>
#define INF 999999999
#define N 500000


int a[N],b[N],c=0;

void merge(int s[],int left,int mid,int right){
  int i,j,k;
  int n1,n2;
  
  n1=mid-left;
  n2=right-mid;
  
  for(i=0;i<n1;i++)a[i]=s[left+i];
  for(i=0;i<n2;i++)b[i]=s[mid+i];
  a[n1]=INF;
  b[n2]=INF;

  i=0;
  j=0;
  for(k=left;k<right;k++){
    c++;
    if(a[i]<=b[j]){
      s[k]=a[i];
      i++;
    }
    else {
      s[k]=b[j];
      j++;
    }
  }
}

void mergeSort(int s[],int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);
    merge(s, left, mid, right);
  }
}

int main(){
  
  int n,i,s[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  mergeSort(s,0,n);

  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",s[i]);
  }
  printf("\n%d\n",c);
  
  return 0;
}

