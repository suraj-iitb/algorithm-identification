#include <stdio.h>
int linearSearch(int*,int*);
  int n,q;
int main(){
  int i,j;
  int key;
  int c = 0;
  int S[10000];
  int T[500];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  printf("%d\n",linearSearch(S,T));
  return 0;
}

int linearSearch(int *S ,int *T){
  int i,j;
  int cnt=0;
  for(j=0;j<q;j++){
    i=0;
    while(i!=n){
    if(S[i]==T[j]){cnt++;
      break;}
    i++;}}
  return cnt;
}
