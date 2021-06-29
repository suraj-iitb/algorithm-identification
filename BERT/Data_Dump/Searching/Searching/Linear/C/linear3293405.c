#include<stdio.h>
#include<stdlib.h>

int linearSearch(int *,int);

int n;

int main(){
  int q,s[10000],t[500],i,j,count;

  count = 0;
  
  scanf("%d",&n);
  if(n < 1 || 10000 < n)exit(0);
  for(i = 0; i < n; i++){
    scanf("%d",&s[i]);
    if(s[i] < 0 || 1000000000 < s[i])exit(0);
  }
  
  scanf("%d",&q);
  if(q < 1 || 500 < q)exit(0);
  for(i = 0; i < q; i++){
    scanf("%d",&t[i]);
    if(t[i] < 0 || 1000000000 < t[i])exit(0);
  }
  
  for(i = 0; i < q; i++){
    for(j = 0; j < q; j++){
      if(i == j)continue;
      if(t[i] == t[j])exit(0);
    }
  }
  for(i = 0; i < q; i++){
    if(linearSearch(s,t[i]) == 1)count++;
  }
  printf("%d\n",count);
  
  return 0;
}

int linearSearch(int *s , int t){
  int i;
  
  for(i = 0; i < n; i++){
    if(s[i] == t)return 1;
  }
  
  return 0;
}
