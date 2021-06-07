#include <stdio.h>

int a[1000000];
int n,m;

int search(int);
int main(){
  int i,j,k,cnt=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&m);

  for(i=0;i<m;i++){
    scanf("%d",&k);
    if(search(k)==1){
      cnt++;
    }
  }

  printf("%d\n",cnt);
  return 0;
}

int search(int k){
  int i,mid;
  int left=0,right=n;

  while(left<right){
    mid=(left+right)/2;
    if(a[mid]==k){
      return 1;
    }
    if(k<a[mid]){
      right=mid;
    }
    else if(k>a[mid])left=mid+1;
  }
  return 0;
}
    

