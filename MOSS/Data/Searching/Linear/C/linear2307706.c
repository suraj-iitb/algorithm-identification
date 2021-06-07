#include <stdio.h>
#define Nmax 10000
#define Qmax 500

int  LinerSearch(int );
int n,S[Nmax];
int main(){
  int q,i;
  int T[Qmax];
  int sum=0;
  int ans;

  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0 ; i<q ; i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0 ; i<q ; i++){
    ans = LinerSearch(T[i]);
    if(ans == T[i]) sum++;
  }

  printf("%d\n",sum);

  return 0;
}

int LinerSearch(int key){
  int i;

  for(i=0 ; i<n ; i++){
    if (S[i] == key) return S[i];
  }

  return S[i];
}
