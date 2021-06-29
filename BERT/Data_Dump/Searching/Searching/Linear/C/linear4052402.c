#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10000

int linerSearch(int *,int ,int);


int main(){
  int S[N],T[N],n,q;
  int i,key,status,cnt=0;


  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %d",&S[i]);
  }

  scanf(" %d",&q);

  for(i=0;i<q;i++){
    scanf(" %d",&key);
    cnt+=linerSearch(S,key,n);
  }


 
   
  printf("%d\n",cnt);

  return 0;
}

int linerSearch(int *S,int key,int n){
  int i=0;
  
  while(1){
    if(S[i]==key)return 1;
    i++;
    if(i==n) return 0;
    
   
   }
  }


