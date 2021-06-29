#include<stdio.h>
#define LEN 10000
int judge(int x,int y){

  if(x == y){
    return 1;
    
  }
  else{
    return 0;
  }
      }

int main(){

  int i,j,n,q,u,s[LEN],t[LEN],a[LEN],count=0;

  
  scanf("%d",&n);

  for(i=0;i < n ; i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);

  for(i = 0;i < q ; i++){
    scanf("%d",&t[i]);
    a[i]=0;
  }
  for(i = 0;i < n ; i++){
    for(j = 0;j < q; j++){

      u = judge(s[i],t[j]);
      
      if(u == 1){
	a[j]++;
	if(a[j] < 2)
	count++;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

