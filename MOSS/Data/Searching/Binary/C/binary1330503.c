#include "stdio.h"

int binarySearch(int [], int [], int i, int n);

main(){

  int i, c=0, n, q, s, t, S[100001], T[50001];

  scanf("%d", &n);

  for(i=0 ; i<n ; i++){

    scanf("%d", &s);
    S[i] = s;
  }

  scanf("%d", &q);

  for(i=0 ; i<q ; i++){

    scanf("%d", &t);
    T[i] = t;
  }

  for(i=0 ; i<q ; i++){
    c += binarySearch(S,T,i,n);
  }

  printf("%d\n", c);

  return 0;

}


int binarySearch(int S[], int T[], int i, int n)
{
  int left=0, right=n, mid;

  while(left < right){
    mid = (left + right)/2;

    if(S[mid] == T[i]){
      return 1;
    }else if(T[i] < S[mid]){
      right = mid;
    }else {
      left = mid + 1;
    }
  }
    return 0;
}
