#include<stdio.h>
#define N 10000
#define Q 500

int main(){
  int n,n1[N],q,q1[Q],i,sum=0,j;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&n1[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&q1[i]);
  }
  
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(n1[j]==q1[i]){
	sum++;
	break;
      }
    }
  }
  printf("%d\n",sum);
  return 0;
}
