#include<stdio.h>
#define N 1000000
#define M 50000
int main(){
  int i,j,k,n,q,a[N],b[M],count=0,l,m,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
    scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&b[j]);
  }
  for(j=0;j<q;j++){
    l=0;
    r=n;
    while(l<r){
      m=(l+r)/2;
      if(b[j]==a[m]){
	count++;
	break;
      }
      if(b[j]>a[m]){
	l=m+1;
      }
      if(b[j]<a[m]){
	r=m;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

