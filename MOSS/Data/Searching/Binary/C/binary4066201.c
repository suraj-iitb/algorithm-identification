#include<stdio.h>
int A[100000],n;
int binarysearch(int key);

int main(){
  int i,j,q,goukei=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&j);
    if(binarysearch(j)) goukei++;
      }
  printf("%d\n",goukei);
  return 0;

}


int binarysearch(int key){
  int l=0,r=n,m;

  while(l<r){
    m=(r+l)/2;
    if(key==A[m])return 1;
    if(key>A[m]) l=m+1;
    else if(key<A[m]) r=m;
  }
  return 0;
}


