#include <stdio.h>

int linerSearch(int);

int s[10000],t[500];
int counter=0,n,q;

int main(){
  int i,j;

  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
    if(linerSearch(t[i])==1)counter++;
  }
  printf("%d\n",counter);  
  
  return 0;
}
int linerSearch(int key){
  int i=0;
  while(s[i]!=key){
    i++;
    if(i==n)return 0;
  }
  return 1;
}
