#include<stdio.h>

int linearsearch(int,int);

int S[10000],T[500]; 


int main( ){

  int n,q,i,count=0;


  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%d",&S[i]);

  }

  scanf("%d",&q);

  for(i=0;i<q;i++){

    scanf("%d",&T[i]);

  }

  for(i=0;i<q;i++){

    count+=linearsearch(T[i],n);
  }

  printf("%d\n",count);
  
  return 0;
}


int linearsearch(int key,int n){

  int i;

  for(i=0;i<n;i++){

    if(key==S[i])return 1;

  }

  return 0;
      
}  
