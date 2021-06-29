#include<stdio.h>
int linearSearch();
int n,S[10000],key;

int main(){
  int i,q,T[10000],C=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    key=T[i];
    if(linearSearch()==-1){
      continue;
    }
    else{
      C++;
    }
  }

  printf("%d\n",C);
}

  int linearSearch(){
    int i=0;
    for(i=0;i<n;i++){
      if(S[i]==key)
	return i;      
    }
    return -1;
  }

