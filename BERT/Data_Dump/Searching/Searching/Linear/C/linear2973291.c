#include <stdio.h>
int main(){
  int n,q,i,j,count=0,flag=0;;
  scanf("%d",&n);
  int S[n];
  for(i =0 ; i<n ;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i =0 ; i<q ;i++){
    scanf("%d",&T[i]);
  }
  
  for(i =0 ;i<q;i++){
    for(j = 0 ;j<n;j++){
      if(flag==1) {
	j=0;
	flag = 0;
      }
      if(S[j] ==T[i]){
	count++;
	flag=1;
	if(i == q-1){
	  break;}
	i++;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

  

