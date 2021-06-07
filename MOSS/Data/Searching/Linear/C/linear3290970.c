#include <stdio.h>
int lenear(int *,int ,int);


int main(){
  int S[10000],i,n,m,cnt=0,nu;

  scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&S[i]);
    }
    
    scanf("%d",&m);
    
    for(i=0;i<m;i++){
      scanf("%d",&nu);
      if(lenear(S,nu,n) == 1) cnt++;
    }
      printf("%d\n",cnt);
      return 0;
    }

int lenear(int *S,int T,int n){
  int i=0;
 
  S[n] = T;
  
  while(S[i] !=  T){
    i++;
    if(i == n) return 0;
  }
    return 1;
    
}

