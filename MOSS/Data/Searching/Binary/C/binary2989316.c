#include<stdio.h>
#define N 100000

int main(void){

  int n, q, C=0, i, j;
  int S[N], T[N];
  int left=0, right, mid, key;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }


  for(j=0;j<q;j++){

    key = T[j];
    right = n;
    left = 0;

    while(left<right){
      mid = (left+right)/2;

      if(S[mid] == key){ C++; break;}
      if(S[mid] != key && S[mid] < key){ left = mid+1;}
      if(S[mid] != key && S[mid] > key){ right = mid;}

    }
  }

  printf("%d\n", C);

  return 0;
}

