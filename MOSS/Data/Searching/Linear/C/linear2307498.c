#include<stdio.h>

int linearSearch(int* ,int);

int n;

int main(){
  int q,i,j;
  int s[10000],t[500];
  int cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    j=linearSearch(s,t[i]);
    if(j!=0){
      cnt++;
    }
  }

  printf("%d\n",cnt);


  return 0;
}

int linearSearch(int *s,int t){
  int i;
  for(i=0;i<n;i++){
    if(t==s[i])
      return 1;
  }
  return 0;
}
