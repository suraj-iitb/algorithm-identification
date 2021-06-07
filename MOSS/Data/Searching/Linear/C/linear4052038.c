#include<stdio.h>
#define N 10000
#define Q 500

int serch(int,int,int []);

int main(){
  int S[N];
  int i,j,q,n,sum=0,t;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
     if(serch(t,n,S)){
	sum++;
      }
  }

  printf("%d\n",sum);  
}

int serch(int t,int n,int A[]){
  int i=0;
  for(i=0;i<n;i++){
    if(A[i]==t){
      return 1;
    }
  }
  return 0;
}

