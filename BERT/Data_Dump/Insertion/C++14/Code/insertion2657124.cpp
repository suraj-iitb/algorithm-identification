#include <bits/stdc++.h>
// #include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {
  int a[100];
  int i,n;
  int before = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(i = 0; i < n; i++){
    if(i > 0){
      printf(" ");
    }
    printf("%d", a[i]);
  }
  printf("\n");

  for(int j = 1; j < n; j++){
    for(i = j; i > 0; i--){
      if(a[i-1] > a[i]){
        before = a[i-1];
        a[i-1] = a[i];
        a[i] = before;
      }
    }
    for(i = 0; i < n; i++){
      if(i > 0) printf(" ");
      printf("%d", a[i]);
    }
    printf("\n");
  }
  
	return 0;
}
