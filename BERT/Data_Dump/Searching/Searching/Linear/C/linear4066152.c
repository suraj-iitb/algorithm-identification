#include<stdio.h>
#define MAX 10000
int search(int[],int,int);


int main(){
  int i,S[MAX],q,key,p,count=0;
 
  scanf("%d",&p);


  for(i=0;i <= p-1;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i <= q-1;i++){
    scanf("%d",&key);
    if(search(S,p,key))count++;
  }


       
  printf("%d\n",count);
  return 0;
}


int search(int S[],int p,int key){
  int i;
  i=0;
  S[p] = key;
  while(S[i] != key)
    {  
      i++;
    }
  return i!= p;
}
  

