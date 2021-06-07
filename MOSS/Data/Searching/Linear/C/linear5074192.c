#include <stdio.h>
#define N 100000

int search(int,int *,int);
int main(){
  int i,sum=0,n,q,s[N],t;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    sum+=search(n,s,t);
  }
  /*for(i=0;i<n;i++){
    for(j=0;j<q;j++){
    if(s[i]==t[j]){
    cnt++;
    }
    }
    }*/
  printf("%d\n",sum);
  return 0;
}

int search(int n,int *s,int key){
  int i;
  for(i=0;i<n;i++){
    if(s[i]==key) return 1;
  }
  return 0;
}
