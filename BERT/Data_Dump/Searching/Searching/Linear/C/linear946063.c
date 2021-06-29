#include<stdio.h>
main(){
  int n,s,q,t,e,f,h=0;
  int c=0;
  scanf("%d",&n);
  int A[10001]={0};
  int B[10001]={0};
  for(s=0;s<n;s++){
    scanf("%d",&A[s]);
  }
  scanf("%d",&q);
  for(t=0;t<q;t++){
    scanf("%d",&B[t]);
  }
  for(f=0;f<q;f++){
    h=0;
    for(e=0;e<n;e++){
      if(A[e]==B[f]){
	if(h!=0)break;
	c=c+1;
	h=h+1;
      }
    }
  }
  printf("%d\n",c);
  return 0;
}
