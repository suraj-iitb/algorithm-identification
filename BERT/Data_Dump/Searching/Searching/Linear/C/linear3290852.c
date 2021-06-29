#include<stdio.h>
#define N 10000
#define Q 500

int find(int ,int *,int );

int main(){
  int x,y,s[N],t[Q],u[Q],i,j,k=0,l=0,a;

  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf("%d",&t[i]);
  }
  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      if(s[i]==t[j]){
	a=s[i];
	if((find(a,u,k))==0)continue;
	else {  
	  u[k]=s[i];
	  k++;
	}
	
      }
    }
  }
  printf("%d\n",k);
  return 0;
}
int find(int a,int *u,int k){
  int i;
  for(i=0;i<k;i++){
    if(a==u[i])return 0;
  }
  return 1;
}

  

