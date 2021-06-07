#include <stdio.h>
#define N 100000
int binarySearch(int);


int n, Sn[N];

int main(){
  int r,q,Tq[N],cnt=0,i,j;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&Sn[i]);
  }
  
  scanf("%d",&q);

  for(j=0;j<q;j++){
    scanf("%d",&Tq[j]);
  }

  for(i=0;i<q;i++){
    r=binarySearch(Tq[i]);
    if(r!=-1){
      cnt++;
    }
  }
  printf("%d\n",cnt);

  return 0;
}

int binarySearch(int key){
  int left=0,right=n,mid;

  while(left<right){
    mid=(left+right)/2;
    if(Sn[mid]==key){
      return 1;
    }
    else if(key<Sn[mid]){
      right=mid;
    }
    else left=mid+1;
  }
  return -1;
}
  

