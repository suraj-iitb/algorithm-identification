#include <stdio.h>

int search(int *,int ,int);

int main(){
  int c=0,i,n,q,s[10001],t;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    scanf("%d",&t);
    c += search(s,t,n);
   }
  printf("%d\n",c);

  return 0;
}

int search(int s[],int t,int n){
  int i = 0;

  while(s[i] != t){
    i++;
    if(i == n)return 0;
  }
  
  return 1;
}

