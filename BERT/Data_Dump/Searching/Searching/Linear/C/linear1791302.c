#include<stdio.h>

#define FOUND 1
#define NOT_FOUND 0

int linearsearch(int *,int ,int );

int main(){
  int i,n,s[10000],q,t[500],c=0;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&t[i]);
    c = c + linearsearch(s,n,t[i]);
  }

  printf("%d\n",c);

  return 0;
}
int linearsearch(int *p,int n,int key){
  int i=0,*a;
  a = p;
  a[n] = key;

  while(a[i] != key){
    i++;
    if(i == n){
      return NOT_FOUND;
    }
  }
  return FOUND;
}
