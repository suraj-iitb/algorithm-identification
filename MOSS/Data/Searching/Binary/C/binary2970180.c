#include<stdio.h>
#define N 1000000
int C[N],n;
int search(int k){
  int l=0,r=n,mi;
  while(l<r){
    mi=(l+r)/2;
    if(k==C[mi]){
      return 1;
    }
    if(k>C[mi]){
      l=mi+1;
    }
    else if(k<C[mi]){
      r=mi;
    }
  }
  return 0;
}
int main(){
  int i,a,b,s=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&C[i]);
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b);
    if(search(b))
      s++;
  }
  printf("%d\n",s);
  return 0;
}

