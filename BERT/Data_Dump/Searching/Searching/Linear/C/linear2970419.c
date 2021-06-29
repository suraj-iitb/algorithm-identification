#include<stdio.h>
int main(){
  int n,q,i,j,k,c,f;
  int s[10000],t[500];

  c=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  
  for(i=0;i<q;i++){
    f=0;
    k=t[i];
    for(j=0;j<n;j++){
      if(s[j]==k){
	if(f==0){
	c++;
	f=1;
	}
      }
    }
  }
  printf("%d\n",c);
  return 0;
}

  

