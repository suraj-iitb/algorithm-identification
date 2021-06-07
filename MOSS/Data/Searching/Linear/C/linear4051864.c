#include <stdio.h>
int linearsearch(int ,int , int *);
int main(){
  int ans=0,l,kazu1,stuff1[10000],kazu2,stuff2,i,j,k;
  scanf("%d",&kazu1);
  for(i=0;i<kazu1;i++){
    scanf("%d",&stuff1[i]);
  }
  scanf("%d",&kazu2);
  for(j=0;j<kazu2;j++){
    scanf("%d",&stuff2);
  l=linearsearch(stuff2,kazu1,stuff1);
  if(l==1){ans++;}
  }
  printf("%d\n",ans);
  return 0;
}


int linearsearch(int stuff2,int kazu1,int *stuff1){
  int i,j,k;
    i=0;
  while(1){
    if(stuff1[i]==stuff2){return 1;break;}
    else if(i==kazu1-1){return 0;break;}
    else {i++;}
  }
}

  
    

