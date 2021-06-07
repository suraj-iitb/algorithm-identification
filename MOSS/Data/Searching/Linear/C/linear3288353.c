#include<stdio.h>
#define N 10000
#define M 500
int main(){
  int i,j,k,n,q,a[N],b[M],count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
    scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&b[j]);
  }
  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(b[j]==a[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

