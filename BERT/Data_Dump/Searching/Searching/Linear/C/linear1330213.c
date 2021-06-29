#include<stdio.h>
int linearSearch(int[],int,int);

main(){
  int i,n,q;
  int res=0;
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



  for(i=0;i<q;i++){
    if(linearSearch(S,T[i],n)==0) res++;
  }

  printf("%d\n",res);



  return 0;
}


int linearSearch(int S[],int key,int n){
  int i;
  for(i=0;i<n;i++){
    if(S[i]==key) return 0;
  }
  return 1;
}
