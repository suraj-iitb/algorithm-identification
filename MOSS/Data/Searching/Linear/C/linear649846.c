#include<stdio.h>

main(){
  int s[10000];
  int t[500];
  int n,q;
  int count=0;
  int i,j;
  int p;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
    for(j=0; j<i; j++){
      if(s[i] == s[j]){
	p = s[i];
	i--;
	n--;
      }
    }
  }
  
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&t[i]);
    for(j=0; j<i; j++){
      if(t[i] == t[j]){
	p = t[i];
	i--;
	q--;
      } 
    }
  }
  
  for(i=0; i<n; i++){
    for(j=0; j<q; j++){
      if(s[i] == t[j]){
	count++;
      }
    }
 }

 printf("%d\n",count);
 return 0;
}
