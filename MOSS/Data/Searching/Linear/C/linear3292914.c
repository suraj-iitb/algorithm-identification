#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10000
#define NOT -1;

int linearSearch(int n,int s[],int t){
  int i;
  for(i=0; i<n; i++){
    if(s[i] == t)return i;
  }
  return NOT;
}

int main(){
  int n,q,sum=0;
  int s[MAX];
  int t[MAX];
  int i,j;
  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&t[i]);
    j = linearSearch(n,s,t[i]);
    if(j != -1)sum++;
  }


  printf("%d\n",sum);
  return 0;
}

