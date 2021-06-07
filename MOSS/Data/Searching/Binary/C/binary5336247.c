#include<stdio.h>
#define N 100001




int n;
int A[N];
int q;
int cnt=0;



int  binary(int key){

  int left=0;
  int right=n;
  int mid;

  if(key<A[0] || A[n-1]<key)return ;

  while(left+1<=right){
    mid=(left+right)/2;
    if(A[mid]==key)return 1;
    if(A[mid]<key)left=mid+1;
    else right=mid;
  }
  return 0;
}





int main(){

  int i;
  int x;


  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&x);
    if(binary(x))cnt++;
  }

  printf("%d\n",cnt);













  return 0;
}

