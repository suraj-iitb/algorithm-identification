#include <stdio.h>

int linearSearch(int,int,int*);


main(){

  int n,q,i,s;
  int S[10000];
  int count = 0;

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&s);
    if(linearSearch(s,n,S) == 0){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
}


int linearSearch(int key,int n,int S[]){
  int i;

  for(i=0;i<n;i++){
    if(key == S[i])return 0;
  }
 
  return 1;
}
