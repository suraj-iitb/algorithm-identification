#include <stdio.h>

int Linear(int S[],int k,int n); //Linear search

int n,q,S[10000],T[500];
int NIL=-1;
int key;
int i,j; 

main(){
  int c=0,k=0;

  scanf("%d",&n); //inpput n integers of S
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q); //input q integers of T
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

  for(j=0 ; j<q ; j++){   
  key = T[j];
  k = Linear(S,key,n); 
    if (k==1)	c++; //add c if the number inside S is as same as one key of T
  }
  
  printf("%d",c);  // ouput of C
  printf("\n");
  return 0;
}

int Linear(int S[],int k,int n){ //search the same value as "T-key" in S
    
  for(i=0 ; i<n ; i++){  //S loop
    if(S[i]==k){
      return 1; //add the number of the same value in S and T
    }
  
  }
return 0;
}
