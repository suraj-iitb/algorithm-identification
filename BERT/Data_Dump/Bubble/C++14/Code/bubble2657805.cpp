#include <bits/stdc++.h>
// #include "bits/stdc++.h"

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
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = n - 1; j >= 1; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        c++;
        flag = true;
      }
    }
  }
  for(int i  = 0; i < n; i++){
    if(i != 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",c);
	return 0;
}
