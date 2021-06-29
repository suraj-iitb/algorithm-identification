#include <stdio.h>
#define N 100000
int n,cnt=0;
int linearSearch(int*,int);
int main(){
  int i,m,S[N],T[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&m);
   for(i=0;i<m;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<m;i++){
    linearSearch(S,T[i]);
  }
    printf("%d\n",cnt);
  return 0;
}
int linearSearch(int *A,int key){
  int i=0;
  while(A[i]!=key){
    i++;
    if(i==n)return 0;
  }
  cnt++;
    return i;
  }

