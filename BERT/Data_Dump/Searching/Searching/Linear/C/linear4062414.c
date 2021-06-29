#include<stdio.h>
int main(){
  int n,s[10000],q,t[500],c=0,i,j,k;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(j=0;j<q;j++){ 
    scanf("%d",&k);
    for(i=0;i<n;i++){
      if(s[i]==k){
	c++;
	break;
      }
    }
  }  
  printf("%d\n",c);
  return 0;
}

