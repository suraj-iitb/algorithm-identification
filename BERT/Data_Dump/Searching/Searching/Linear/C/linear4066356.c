#include <stdio.h>

int linersearch(int);

int S[10000],T[500],n1,n2,kakunin[10000];

int main(){

  int i,j,count = 0;

  scanf("%d",&n1);

  for(i = 0; i < n1;i++) scanf("%d",&S[i]);

  scanf("%d",&n2);

  for(i = 0; i < n2 ; i++) scanf("%d",&T[i]);


  for(j = 0;j < n2;j++){
    i = linersearch(T[j]);
    if(i == 1) count++;
  }


  printf("%d\n",count);

}

int linersearch(int key){
  int i = 0;

  S[n1] = key;

  while(S[i] != key){
    i++;

    if(i == n1) return -1;
  }
    return 1;
}

