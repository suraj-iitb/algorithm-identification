#include<stdio.h>

int Linearsearch(int *,int,int);

int main(){
  int i,j=0,n,q;
  int S[10000+1],T[10000+1];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

for(i=0;i<q;i++){
if(Linearsearch(S,n,T[i])==1)j++;
}

printf("%d\n",j );
}


int Linearsearch(int S[],int n,int key){
  int i;

  for(i=0;i<n;i++){
    if(S[i] == key)return 1;
  }
  return 0;
}
