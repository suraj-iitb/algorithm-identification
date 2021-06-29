#include <stdio.h>

int linearSearch(int);
int s[10000],n;

main(){
  int t[10000];
  int i,j,c=0,q;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    c+=linearSearch(t[i]);
  }

  printf("%d\n",c);
  return 0;
}

int linearSearch(int key){
  int i;

  i=0;
  s[n]=key;
  while(s[i]!=key){
    i++;
    if(i==n) return 0;
  }
  return 1;
}
  

  
  
