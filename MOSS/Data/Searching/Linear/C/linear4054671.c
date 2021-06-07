#include <stdio.h>
#define TRUE 1
#define FALSE 0

int linearSearch(int A[],int key,int n){
  int i=0;
  A[n] = key;
  

  while(i != n){
    if(A[i] == key) return TRUE;
    i++;
  }

  return FALSE;
}

int main(){
  int n,q,i,t;
  int s[10001];
  int cnt=0;

  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&s[i]);

  scanf("%d",&q);
  
  for(i=0; i<q; i++){
    scanf("%d",&t);
    if(linearSearch(s,t,n) == TRUE) cnt++;
  }

  printf("%d\n",cnt);

  return 0;
  
}

