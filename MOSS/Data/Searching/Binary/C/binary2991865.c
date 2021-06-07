#include <stdio.h>

#define N 100000
#define Q 50000
#define S 1000000000
#define T 1000000000

int BSearch(int,int,int*);

int main(){
  int i,n[N],q[Q],non,noq,ans=0;

  scanf("%d",&non);
  for(i=0;i<non;i++){
    scanf("%d",&n[i]);
  }
  scanf("%d",&noq);
  for(i=0;i<noq;i++){
    scanf("%d",&q[i]);
  }

  for(i=0;i<noq;i++){
    ans += BSearch(q[i],non,n);
  }

  printf("%d\n",ans);
  
  return 0;
}

int BSearch(int voq,int non,int* n){
  int i,l=0,m,r=non;
  while(l < r){
    m = (l+r)/2;
    if(voq == n[m]){
      return 1;
    }
    else if(voq<n[m]){
      r=m;
    }
    else if(voq>n[m]){
      l=m+1;
    }
  }
  return 0;
}


		  

