#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){

  int s[10000],t[500],n,q,i,j;
  int count = 0;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&s[i]);
    for(j = 0;j < i;j++){
      if(s[i] == s[j]){
	i--;
	n--;
      }
    }
  }

  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&t[i]);
    for(j = 0;j < i;j++){
      if(t[i] == t[j]){
	i--;
	q--;
      }
    }
  }

  for(i = 0;i < n;i++){
    for(j = 0;j < q;j++){
      if(s[i] == t[j]){
	count++;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
