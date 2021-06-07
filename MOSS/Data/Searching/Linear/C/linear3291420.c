#include<stdio.h>

int listsearch(int *s,int *t,int m,int n){
  int i,j=0,count=0;
  
  for(i=0;i<m;i++){
    s[n]=t[i];
    while(s[j]!=t[i]){
      j++;  
    }
    if(j!=n)count++;
    j=0;
  }
  return count;
}

int main(){

  int s[10000],t[500],i,n,m;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&m);
  for(i=0;i<m;i++)
    scanf("%d",&t[i]);
 
  printf("%d\n",listsearch(s,t,m,n));
  return 0;
  }

