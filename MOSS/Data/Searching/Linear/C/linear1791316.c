#include<stdio.h>

int main(){

  int n,q;
  int i,j;
  int s[100000],t[100000],c=0;

  scanf("%d",&n);

  for(i=0; i < n; i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);

  for(j=0; j < q; j++){
    scanf("%d",&t[j]);
    i=0;
    s[n]=t[j];
    while(s[i]!=t[j]){
      i++;
    }
    if(i !=n) c++;
  }

  printf("%d\n",c);

  return 0;
}
