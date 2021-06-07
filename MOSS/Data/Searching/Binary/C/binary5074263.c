#include<stdio.h>
#include<stdlib.h>
#define N 100000

char binarysearch(int);

int S[N];
int T[N];
int n,q;

int main(){
  int i,j;
  int result=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

  for(j=0;j<q;j++){
    if( binarysearch(T[j])== 'm') result=result+1;
    else if(binarysearch(T[j])=='N')result=result;
    else result=result;
  }
  printf("%d\n",result);
  return 0;
}

char binarysearch(int T){
  int left;
  int right;
  int mid;
  int key;

  key=T;
  left=0;
  right=n;
  while(left<right){
    mid=(right+left)/2;
    if(S[mid]==key){
      return 'm';
    }
    else if(key<S[mid]){
      right=mid;
    }
    else left=mid+1;
  }
  return 'N';
}

