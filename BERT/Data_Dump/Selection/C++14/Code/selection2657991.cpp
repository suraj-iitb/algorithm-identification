#include <bits/stdc++.h>
// #include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
 
using namespace std;
 
typedef long long ll;
 
int main() {
  int n;
  scanf("%d", &n);
 
  int a[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  
  int c = 0;
  int small;
  for(int i = 0; i < n-1; i++){
    small = i;
    for(int j = i; j < n; j++){
      if(a[j] < a[small]){
        small = j;
      } 
    }
    swap(a[i],a[small]);
    if(i != small) c++;    
  }

  for(int i  = 0; i < n; i++){
    if(i != 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",c);
    return 0;
}
