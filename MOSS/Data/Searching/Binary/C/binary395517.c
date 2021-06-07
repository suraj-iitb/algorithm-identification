#include <stdio.h>

int isIncludedInS(int x);

int n,q;
int S[100000],T[50000];
int count = 0;

main(){

  int i;
  int tmp;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&tmp);
    count += isIncludedInS(tmp);
  }

  printf("%d\n",count);

  return 0;

}

int isIncludedInS(int x){

  int i,j;
  int min,max;
  int middle;

  min = 0;
  max = n;
  while(min <= max){
    middle = (max+min)/2;
    if(x > S[middle]){
      min = middle + 1;
    }else if(x < S[middle]){
      max = middle - 1;
    }else if(x == S[middle]){
      return 1;
    }
  }
  return 0;

}
