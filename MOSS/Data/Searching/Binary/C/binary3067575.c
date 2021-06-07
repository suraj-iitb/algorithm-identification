#include <stdio.h>

int BinarySearch(int, int, int*);


int main(){

  int n,q,i,s;
  int S[1000000];
  int count = 0;

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&s);
    if(BinarySearch(s,n,S) == 0){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
}


int BinarySearch(int key,int n,int S[]){

  int l=0,m,r;

  r = n;

  while(l < r){
    m = (r + l)/2;

    if(S[m] == key)return 0;

    else if(S[m] > key)r = m;

    else l = m+1;
  }

  return 1;
}

