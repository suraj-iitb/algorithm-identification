#include <stdio.h>
#define N 500000
#define INFTY 1000000000
void merge(int *,int,int,int);
void sort(int *,int,int);
int right[N/2+2],left[N/2+2],cnt=0;

int main() {
  int i,n,S[N];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  sort(S,0,n);
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",S[i]);
    else printf("%d ",S[i]);
  }
  printf("%d\n",cnt);
  return 0;
}
void merge(int S[],int left_s,int mid,int right_s){
  int s1 = mid - left_s;
  int s2 = right_s - mid;
  int i,j=0,m;
  for(i=0;i<s1;i++)left[i]=S[left_s+i];
  for(i=0;i<s2;i++)right[i]=S[mid+i];
  left[s1]=INFTY;
  right[s2]=INFTY;
  i=0;
  for(m=left_s;m<right_s;m++){
    cnt++;
    if(right[j]>=left[i]){
      S[m]=left[i];
      i++;
    }
    else {
      S[m]=right[j];
      j++;
    }
  }
}
void sort(int S[],int left_s,int right_s){
  int mid;
  if(left_s + 1 < right_s){
    mid=(left_s + right_s)/2;
    sort(S,left_s,mid);
    sort(S,mid,right_s);
    merge(S,left_s,mid,right_s);
  }
}

