#include <stdio.h>
int S[10000];
int n;
int linearSearch(int);

int main(){
  int count=0;
  int T[500];
  int q,i;
  int re;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  } 
  for(i=0;i<q;i++){
    count+=linearSearch(T[i]);
  }
  printf("%d\n",count);
  return 0;
}
int linearSearch(int key){
  int i;
 for(i=0;i<n;i++){
    if(S[i]==key){
      return 1;
    }     
 }
 return 0;
}
