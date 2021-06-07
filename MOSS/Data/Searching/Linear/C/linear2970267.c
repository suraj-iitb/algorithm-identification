#include <stdio.h>

#define N 10000
#define Q 500
#define S 1000000000
#define T 1000000000

int LSearch(int,int,int*);

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
    ans += LSearch(q[i],non,n);
  }

  printf("%d\n",ans);
  
  return 0;
}

int LSearch(int voq,int non,int* n){
  int i;
  for(i=0;i<non;i++){
    if(n[i] == voq){
      return 1;
    }
  }
  return 0;
}


		  

